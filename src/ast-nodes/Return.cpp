#include "Return.h"
#include "Expression.h"
#include "CFG.h"
#include "IRInstr.h"

string Return::buildIR(CFG *cfg)
{
    string exprTmpVar = cfg->var_to_asm(retExp->buildIR(cfg));
    cfg->add_instruction(new CopyInstr(retExp->get_type(), "%eax", exprTmpVar));
    return "";
}