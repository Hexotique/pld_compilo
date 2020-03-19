#include "Program.h"

void Program::addFunction(Function *f)
{
    fcts.push_back(f);
}

void Program::buildIR(CFG *cfg)
{
}