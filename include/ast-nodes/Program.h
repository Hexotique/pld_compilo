#pragma once

#include <vector>

#include "ASTNode.h"
#include "Function.h"

using namespace std;

class Program : public ASTNode
{
public:
    Program() {}

    void addFunction(Function *f);

    void buildIR(CFG *cfg);

protected:
    vector<Function *> fcts;
};