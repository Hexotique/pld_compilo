#pragma once

#include <string>

using namespace std;

class CFG;

class ASTNode
{
public:
    virtual string buildIR(CFG *cfg) = 0;
};