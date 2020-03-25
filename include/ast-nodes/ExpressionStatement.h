#include <string>

#include "Statement.h"

class CFG;
class Expression;

using namespace std;

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression *expr)
        : expression(expr){};

    string buildIR(CFG *cfg);

protected:
    Expression *expression;
};