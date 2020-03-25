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
    string dest = cfg->var_to_asm(dec->get_identifier());
    string source = cfg->var_to_asm(init->buildIR(cfg));
    cfg->add_instruction(new CopyInstr(dec->get_type(), dest, source));
    return source;
}