#pragma once

#include "ASTNode.h"

class Expression : public ASTNode
{
public:
    virtual void buildIR(CFG *cfg) = 0;

protected:
};