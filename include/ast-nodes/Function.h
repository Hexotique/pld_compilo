#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"

using namespace std;

class Param;
class Type;
class Block;

class Function : public ASTNode
{
public:
    Function(string fn, Type *t, Block *b)
        : fctName(fn), retType(t), fctBlock(b) {}

    void addParam(Param *);

    void buildIR(CFG *cfg);

    string getFctName();

protected:
    string fctName;
    Type *retType;
    vector<Param *> fctParams;
    Block *fctBlock;
};