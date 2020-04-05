#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"

using namespace std;

class Declaration;
class Type;
class Block;

class Function : public ASTNode
{
public:
    Function(string fn, Type *t, Block *b, vector<Declaration *> fp)
        : fctName(fn), retType(t), fctBlock(b), fctParams(fp) {}

    void addParam(Declaration *);

    string buildIR(CFG *cfg);

    string getFctName();

    vector<Declaration *> getParams();

protected:
    string fctName;
    Type *retType;
    vector<Declaration *> fctParams;
    Block *fctBlock;
};