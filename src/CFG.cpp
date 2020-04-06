#include "CFG.h"
#include "FuncDefinition.h"
#include "FuncDeclaration.h"
#include "BasicBlock.h"
#include "SymbolTable.h"
#include "Symbol.h"
#include "Type.h"
#include "IRInstr.h"
#include "Declaration.h"

CFG::CFG(FuncDefinition *f, map<string, FuncDeclaration *> gs)
    : ast(f), globalFuncs(gs), tmp_var_count(0)
{
    BasicBlock *bb = add_basic_block();
    set_current_block(bb);
    symTab = new SymbolTable();
}

BasicBlock *CFG::get_current_block()
{
    return currentBlock;
}

void CFG::set_current_block(BasicBlock *block)
{
    currentBlock = block;
}

BasicBlock *CFG::add_basic_block()
{
    BasicBlock *bb = new BasicBlock(this, gen_block_label());
    blocks.push_back(bb);
    return bb;
}

void CFG::gen_asm(ostream &o)
{
    o << ".text" << endl;
    o << ".globl\t" << ast->getFctDec()->getFctName() << endl;
    o << ast->getFctDec()->getFctName() << ':' << endl;
    gen_asm_prologue(o);
    for (BasicBlock *block : blocks)
    {
        block->gen_asm(o);
    }
}

void CFG::gen_asm_prologue(ostream &o)
{
    o << "\tpushq\t%rbp" << endl;
    o << "\tmovq\t%rsp, %rbp" << endl;
    o << "\tsubq\t$" << symTab->get_cur_index() + 8 << ", %rsp" << endl;
    for (int i = 0; i < ast->getFctDec()->getParams().size(); i++)
    {
        string reg = "";
        string mov_op = "";
        string dest = var_to_asm(ast->getFctDec()->getParams()[i]->get_identifier());
        switch (ast->getFctDec()->getParams()[i]->get_type()->get_size())
        {
        case 1:
            mov_op = "movb";
            reg = param_reg_8[i];
            break;
        case 4:
            mov_op = "movl";
            reg = param_reg_32[i];
            break;
        case 8:
            mov_op = "movq";
            reg = param_reg_64[i];
        default:
            break;
        }
        o << "\t" << mov_op << "\t" << reg << ", " <<  dest << endl;
    }
}

void CFG::gen_asm_epilogue(ostream &o)
{
    o << "\taddq\t$" << symTab->get_cur_index() + 8 << ", %rsp" << endl;
    o << "\tpopq\t%rbp" << endl;
    o << "\tretq" << endl;
}

void CFG::enter_scope()
{
    symTab->enter_scope();
}

void CFG::exit_scope()
{
    symTab->exit_scope();
}

void CFG::add_instruction(IRInstr *instr)
{
    instr->set_block(currentBlock);
    currentBlock->add_IRInstr(instr);
}

Symbol *CFG::add_to_symbol_table(string label, Type *t)
{
    Symbol *s = symTab->local_lookup(label);
    if (s != nullptr)
    {
        cerr << "error: redeclaration of '" << label << "' variable" << endl;
        exit(1);
    }
    return symTab->insert(label, t);
}

Symbol *CFG::create_temp_var(Type *t)
{
    string label = "!tmp" + to_string(tmp_var_count++ + t->get_size());
    return add_to_symbol_table(label, t);
}

string CFG::var_to_asm(string identifier)
{
    Symbol *s = symTab->lookup(identifier);
    if (s == nullptr)
    {
        cerr << "error: '" << identifier << "' undeclared" << endl;
        exit(1);
    }
    return to_string(-1 * s->get_index()) + "(%rbp)";
}

Type *CFG::get_var_type(string identifier)
{
    Symbol *s = symTab->lookup(identifier);
    if (s == nullptr)
    {
        cerr << "error: '" << identifier << "' undeclared" << endl;
        exit(1);
    }
    return s->get_type();
}

string CFG::gen_block_label()
{
    return ast->getFctDec()->getFctName() + "_LB" + to_string(blocks.size());
}

map<string, FuncDeclaration *> CFG::get_global_funcs()
{
    return globalFuncs;
}