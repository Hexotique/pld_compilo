#pragma once

class CFG;

class ASTNode
{
public:
    virtual void buildIR(CFG *cfg) = 0;
};