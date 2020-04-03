#include <string>

#include "Expression.h"

using namespace std;

class BitExpr : public Expression
{
public:
    BitExpr(Expression *ex1, Expression *ex2, string s)
        : leftExpr(ex1), rightExpr(ex2), op(s) {}

    ~BitExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *leftExpr;
    Expression *rightExpr;
    string op;
};
