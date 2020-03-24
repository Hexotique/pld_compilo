#include "BasicBlock.h"
#include "CFG.h"

void BasicBlock::gen_asm(ostream &o)
{
    o << label << ":" << endl;
    for (IRInstr *instr : instrs)
    {
        instr->gen_asm(o);
    }

    if (exit_true == nullptr)
    {
        return cfg->gen_asm_epilogue(o);
    }
    else if (exit_false == nullptr)
    {
        exit_true->gen_asm(o);
    }
    else
    {
        //assembly for if else block etc
    }
}