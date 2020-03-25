#include "CFG.h"
#include "Function.h"
#include "BasicBlock.h"
#include "SymbolTable.h"
#include "Symbol.h"
#include "Type.h"
#include "IRInstr.h"

CFG::CFG(Function *f)
    : ast(f)
{
    BasicBlock *bb = new BasicBlock(this, f->getFctName());
    add_basic_block(bb);

    SymbolTable *st = new SymbolTable();
    currentTable = st;
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

string CFG::var_to_asm(string identifier)
{
    Symbol *s = get_symbol_table()->lookup(identifier);

    return to_string(-1*s->get_index()) + "(%rbp)";
}

void CFG::gen_asm_prologue(ostream &o)
{
    o << "\tpushq\t%rbp" << endl;
    o << "\tmovq\t%rsp,\t%rbp" << endl;

    // for allocation of variables, pointers relative to base pointer
}

void CFG::gen_asm_epilogue(ostream &o)
{
    o << "\tpopq\t%rbp" << endl;
    o << "\tret" << endl;
}

void CFG::enter_scope()
{
}

void CFG::exit_scope()
{
}

void CFG::add_instruction(IRInstr *instr) 
{
    instr->set_block(currentBlock);
    currentBlock->add_IRInstr(instr);
}

Symbol *CFG::add_to_symbol_table(string label, Type *t)
{
    return get_symbol_table()->insert(label, t);
}

Symbol *CFG::create_temp_var(Type *t)
{
    int next_index = get_symbol_table()->get_cur_index();
    string label = "!tmp" + to_string(next_index + t->get_size());
    return add_to_symbol_table(label, t);
}

SymbolTable *CFG::get_symbol_table()
{
    return currentTable;
}

