#include "NotExpr.h"
#include "Symbol.h"
#include "CFG.h"
#include "IRInstr.h"

string NotExpr::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());
    string src = cfg->var_to_asm(expr->buildIR(cfg));

    cfg->add_instruction(new CmpInstr(get_type(), dest, "$0", src, "e"));
    return s->get_identifier();
}
