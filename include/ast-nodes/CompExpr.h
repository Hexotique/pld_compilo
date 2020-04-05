#include <string>

#include "Expression.h"

using namespace std;

class CompExpr : public Expression
{
public:
    CompExpr(Expression *ex1, Expression *ex2, string s)
        : leftExpr(ex1), rightExpr(ex2), op(s) {}

    ~CompExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *leftExpr;
    Expression *rightExpr;
    string op;
};
