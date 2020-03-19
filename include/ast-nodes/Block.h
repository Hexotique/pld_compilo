#pragma once

#include <vector>

#include "ASTNode.h"
#include "Statement.h"

using namespace std;

class Block : public ASTNode
{
public:
    void addStatement(Statement *);

    void buildIR(CFG *);

protected:
    vector<Statement *> statements;
};