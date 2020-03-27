#include <string>

#include "Expression.h"

using namespace std;

class MultDivExpr : public Expression
{
public:
    MultDivExpr(Expression *ex1, Expression *ex2, string s)
        : leftExpr(ex1), rightExpr(ex2), op(s) {}

    ~MultDivExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *leftExpr;
    Expression *rightExpr;
    string op;
};
