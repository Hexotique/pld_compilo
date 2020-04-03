#include "CompExpr.h"
#include "Symbol.h"
#include "CFG.h"
#include "IRInstr.h"

string CompExpr::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());
    string src1 = cfg->var_to_asm(leftExpr->buildIR(cfg));
    string src2 = cfg->var_to_asm(rightExpr->buildIR(cfg));

    if (op == "==")
    {
        cfg->add_instruction(new EquInstr(get_type(), dest, src1, src2));
    }
    else if (op == "<"){
        cfg->add_instruction(new InfInstr(get_type(), dest, src1, src2));
    }
    else if (op == ">"){
        cfg->add_instruction(new SupInstr(get_type(), dest, src1, src2));
    }
    else if (op == "!="){
        cfg->add_instruction(new InequInstr(get_type(), dest, src1, src2));
    }
    else if (op == "<="){
        cfg->add_instruction(new InfEquInstr(get_type(), dest, src1, src2));
    }
    else {
        cfg->add_instruction(new SupEquInstr(get_type(), dest, src1, src2));
    }
    return s->get_identifier();
}
