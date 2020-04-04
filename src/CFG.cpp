#include "CFG.h"
#include "Function.h"
#include "BasicBlock.h"
#include "SymbolTable.h"
#include "Symbol.h"
#include "Type.h"
#include "IRInstr.h"

CFG::CFG(Function *f)
    : ast(f), tmp_var_count(0)
{
    BasicBlock *bb = new BasicBlock(this, f->getFctName());
    add_basic_block(bb);
    symTab = new SymbolTable();
}

BasicBlock *CFG::get_current_block()
{
    return currentBlock;
}

void CFG::add_basic_block(BasicBlock *bb)
{
    blocks.push_back(bb);
    currentBlock = bb;
}

void CFG::gen_asm(ostream &o)
{
    o << ".text" << endl;
    o << ".globl\t" << ast->getFctName() << endl;
    o << ast->getFctName() << ':' << endl;
    gen_asm_prologue(o);
    for (BasicBlock *block : blocks)
    {
        block->gen_asm(o);
    }
}

void CFG::gen_asm_prologue(ostream &o)
{
    o << "\tpushq\t%rbp" << endl;
    o << "\tmovq\t%rsp,\t%rbp" << endl;
}

void CFG::gen_asm_epilogue(ostream &o)
{
    o << "\tpopq\t%rbp" << endl;
    o << "\tret" << endl;
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

