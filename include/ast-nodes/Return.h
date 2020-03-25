#pragma once

#include <string>

#include "Statement.h"

class Type;
class Expression;
class CFG;

using namespace std;

class Return : public Statement
{
public:
    Return(Type *type, Expression *e)
        : retType(type), retExp(e){};

    string buildIR(CFG *cfg);

protected:
    Type *retType;
    Expression *retExp;
};