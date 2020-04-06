#include "Program.h"
#include "CFG.h"
#include "FuncDefinition.h"

vector<FuncDefinition *> Program::getFunctions()
{
    return fcts;
}

void Program::addFunction(FuncDefinition *f)
{
    fcts.push_back(f);
}

vector<CFG *> Program::buildIR()
{
    vector<CFG *> cfgs;
    for (FuncDefinition *f : fcts)
    {
        CFG *cfg = new CFG(f, map<string, Symbol *>());
        f->buildIR(cfg);
        cfgs.push_back(cfg);
    }
    return cfgs;
}