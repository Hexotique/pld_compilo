#include "Assignment.h"
#include "CFG.h"
#include "IRInstr.h"

string Assignment::buildIR(CFG *cfg)
{
    string dest = cfg->var_to_asm(identifier);
    string source = cfg->var_to_asm(expr->buildIR(cfg));
    cfg->add_instruction(new CopyInstr(expr->get_type(), dest, source));
    return identifier;
}