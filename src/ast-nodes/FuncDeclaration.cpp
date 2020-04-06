#include "FuncDeclaration.h"
#include "Declaration.h"
#include "Type.h"
#include "CFG.h"

void FuncDeclaration::addParam(Declaration *dec)
{
    fctParams.push_back(dec);
}

string FuncDeclaration::buildIR(CFG *cfg)
{
    for (Declaration *param : fctParams)
    {
        param->buildIR(cfg);
    }
    return "";
}

string FuncDeclaration::getFctName()
{
    return fctName;
}

Type *FuncDeclaration::getRetType()
{
    return retType;
}

vector<Declaration *> FuncDeclaration::getParams()
{
    return fctParams;
}