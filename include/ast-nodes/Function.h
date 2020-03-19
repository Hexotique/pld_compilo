#pragma once

#include <vector>

#include "ASTNode.h"
#include "Param.h"
#include "Type.h"

using namespace std;

class Function : public ASTNode
{
public:
    Function(string fn, string rt)
        : fctName(fn), retType(rt) {}

    void addParam(Param *);

    void buildIR(CFG *cfg);

protected:
    string fctName;
    Type retType;
    vector<Param *> fctParams;
};