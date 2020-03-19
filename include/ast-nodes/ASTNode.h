#pragma once

#include "CFG.h"

class ASTNode
{
public:
    virtual void buildIR(CFG *cfg) = 0;
};