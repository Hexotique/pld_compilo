#pragma once

#include <string>

#include "ASTNode.h"

using namespace std;

class Type;
class Param;

class Param : public ASTNode
{
public:
    Param(Type *t, string l)
        : type(t), label(l){};

    void buildIR(CFG *);

protected:
    Type *type;
    string label;
};