#include "Const.h"
#include "CFG.h"
#include "Symbol.h"
#include "IRInstr.h"

string Const::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());
    cfg->add_instruction(new LdConstInstr(get_type(), dest, to_string(value)));
    return s->get_identifier();
}