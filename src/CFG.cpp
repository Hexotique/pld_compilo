#include "CFG.h"
#include "Function.h"
#include "BasicBlock.h"

CFG::CFG(Function *f)
    : ast(f)
{
    BasicBlock *bb = new BasicBlock(this, f->getFctName());
    add_basic_block(bb);
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
    o << "\t.globl\t" << ast->getFctName() << endl;
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