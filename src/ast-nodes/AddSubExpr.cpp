#include "AddSubExpr.h"
#include "Symbol.h"
#include "CFG.h"

string AddSubExpr::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());
    return "";
}