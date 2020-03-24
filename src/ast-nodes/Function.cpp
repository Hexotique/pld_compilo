#include "Function.h"
#include "Param.h"
#include "Block.h"

void Function::buildIR(CFG *cfg)
{
    for (Param *param : fctParams)
    {
        param->buildIR(cfg);
    }
    fctBlock->buildIR(cfg);
}

string Function::getFctName()
{
    return fctName;
}