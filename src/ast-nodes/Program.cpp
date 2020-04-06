#include "Program.h"
#include "CFG.h"
#include "FuncDefinition.h"
#include "FuncDeclaration.h"

vector<FuncDefinition *> Program::getFunctions()
{
    return fctDefs;
}

void Program::addFunction(FuncDefinition *f)
{
    fctDefs.push_back(f);
}

vector<CFG *> Program::buildIR()
{
    vector<CFG *> cfgs;
    map<string, FuncDeclaration *> declaredFuncs;
    for(FuncDeclaration *f : fctDecs)
    {
        declaredFuncs.insert(make_pair(f->getFctName(), f));
    }

    for (FuncDefinition *f : fctDefs)
    {
        if (declaredFuncs.count(f->getFctDec()->getFctName()) == 0)
        {
            declaredFuncs.insert(make_pair(f->getFctDec()->getFctName(), f->getFctDec()));
        }
        CFG *cfg = new CFG(f, declaredFuncs);
        f->buildIR(cfg);
        cfgs.push_back(cfg);
    }
    return cfgs;
}