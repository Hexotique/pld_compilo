#include "BitExpr.h"
#include "Symbol.h"
#include "CFG.h"
#include "IRInstr.h"

string BitExpr::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());
    string src1 = cfg->var_to_asm(leftExpr->buildIR(cfg));
    string src2 = cfg->var_to_asm(rightExpr->buildIR(cfg));

    if (op == "&")
    {
        cfg->add_instruction(new AndInstr(get_type(), dest, src1, src2));
    }
    else if (op == "^"){
        cfg->add_instruction(new XOrInstr(get_type(), dest, src1, src2));
    }
    else {
        cfg->add_instruction(new OrInstr(get_type(), dest, src1, src2));
    }
    return s->get_identifier();
}
