#include "Function.h"
#include "CFG.h"
#include "Declaration.h"
#include "Block.h"

string Function::buildIR(CFG *cfg)
{
    for (Declaration *param : fctParams)
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

vector<Declaration *> Function::getParams()
{
    return fctParams;
}