#pragma once

#include <string>

#include "ASTNode.h"

using namespace std;

class Param : public ASTNode
{
public:
    void buildIR(CFG *);

protected:
    string label;
};