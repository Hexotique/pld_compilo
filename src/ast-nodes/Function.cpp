#include "Function.h"
#include "Param.h"
#include "Block.h"

string Function::buildIR(CFG *cfg)
{
    for (Param *param : fctParams)
    {
        param->buildIR(cfg);
    }
    fctBlock->buildIR(cfg);
    return "";
}

string Function::getFctName()
{
    return fctName;
}