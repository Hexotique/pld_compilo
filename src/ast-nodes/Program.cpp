#include "Program.h"
#include "CFG.h"
#include "Function.h"

vector<Function *> Program::getFunctions()
{
    return fcts;
}

void Program::addFunction(Function *f)
{
    fcts.push_back(f);
}

vector<CFG *> Program::buildIR()
{
    vector<CFG *> cfgs;
    for (Function *f : fcts)
    {
        CFG *cfg = new CFG(f, map<string, Symbol *>());
        f->buildIR(cfg);
        cfgs.push_back(cfg);
    }
    return cfgs;
}