#pragma once

#include "ASTNode.h"
#include "Type.h"

class Expression : public ASTNode
{
public:
    Expression(Type *t = new Type("int"))
        : type(t) {}

    Type *get_type();

    virtual string buildIR(CFG *cfg) = 0;

protected:
    Type *type;
};