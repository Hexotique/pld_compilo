#include "FuncDefinition.h"
#include "FuncDeclaration.h"
#include "CFG.h"
#include "Block.h"

string FuncDefinition::buildIR(CFG *cfg)
{
    fctDec->buildIR(cfg);
    fctBlock->buildIR(cfg);
    return "";
}

FuncDeclaration *FuncDefinition::getFctDec()
{
    return fctDec;
}