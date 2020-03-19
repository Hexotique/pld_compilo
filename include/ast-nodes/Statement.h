#pragma once

#include "ASTNode.h"

class Statement : public ASTNode
{
public:
    void buildIR(CFG *);

protected:
};