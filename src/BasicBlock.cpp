#include "BasicBlock.h"
#include "CFG.h"
#include "IRInstr.h"
#include "Type.h"

CFG *BasicBlock::get_cfg()
{
    return cfg;
}

string BasicBlock::get_label()
{
    return label;
}

string BasicBlock::get_test_var_name()
{
    return test_var_name;
}

BasicBlock *BasicBlock::get_exit_true()
{
    return exit_true;
}

BasicBlock *BasicBlock::get_exit_false()
{
    return exit_false;
}

void BasicBlock::set_test_var_name(string tvn)
{
    test_var_name = tvn;
}

void BasicBlock::set_exit_true(BasicBlock *bb)
{
    exit_true = bb;
}

void BasicBlock::set_exit_false(BasicBlock *bb)
{
    exit_false = bb;
}

void BasicBlock::add_IRInstr(IRInstr *instr)
{
    instrs.push_back(instr);
    instr->set_block(this);
}

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
        o << "\tjmp\t" << exit_true->get_label() << endl;
    }
    else
    {
        string src = cfg->var_to_asm(test_var_name);
        Type *type = cfg->get_var_type(test_var_name);
        string cmp_op = "";

        switch (type->get_size())
        {
        case 1:
            cmp_op = "cmpb";
            break;
        case 4:
            cmp_op = "cmpl";
            break;
        case 8:
            cmp_op = "cmpq";
            break;
        default:
            break;
        }

        o << "\t" << cmp_op << "\t$0, " << src << endl;
        o << "\tje\t" << exit_false->get_label() << endl;
    }
}