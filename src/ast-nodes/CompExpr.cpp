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
    string comparison = "";

    if (op == "==")
    {
        comparison = "e";
    }
    else if (op == "<")
    {
        comparison = "l";
    }
    else if (op == ">")
    {
        comparison = "g";
    }
    else if (op == "!=")
    {
        comparison = "ne";
    }
    else if (op == "<=")
    {
        comparison = "le";
    }
    else if (op == ">=")
    {
        comparison = "ge";
    }
    cfg->add_instruction(new CmpInstr(get_type(), dest, src1, src2, comparison));
    return s->get_identifier();
}
