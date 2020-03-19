#pragma once

#include "ASTNode.h"

class Expression : public ASTNode
{
public:
    void buildIR(CFG *cfg);
};