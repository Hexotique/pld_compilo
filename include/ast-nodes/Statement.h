#pragma once

#include "ASTNode.h"

class CFG;

class Statement : public ASTNode
{
public:
    virtual string buildIR(CFG *) = 0;

protected:
};