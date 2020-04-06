#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"

using namespace std;

class Declaration;
class Type;
class CFG;

class FuncDeclaration : public ASTNode
{
public:
    FuncDeclaration(string fn, Type *t, vector<Declaration *> fp)
        : fctName(fn), retType(t), fctParams(fp) {}

    void addParam(Declaration *);

    string buildIR(CFG *cfg);

    string getFctName();

    Type *getRetType();

    vector<Declaration *> getParams();

protected:
    string fctName;
    Type *retType;
    vector<Declaration *> fctParams;
};



