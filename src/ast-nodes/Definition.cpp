#include "Definition.h"
#include "Declaration.h"
#include "Type.h"
#include "Expression.h"
#include "IRInstr.h"
#include "CFG.h"
#include "SymbolTable.h"
#include "Symbol.h"

string Definition::buildIR(CFG *cfg)
{
    dec->buildIR(cfg);
    string var = cfg->var_to_asm(dec->get_identifier());
    string exprTmpVar = cfg->var_to_asm(init->buildIR(cfg));
    cfg->add_instruction(new CopyInstr(dec->get_type(), var, exprTmpVar));
    return var;
}