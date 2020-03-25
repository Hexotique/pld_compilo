#include <string>

#include "Expression.h"

using namespace std;

class AddSubExpr : public Expression
{
public:
    AddSubExpr(Expression *ex1, Expression *ex2, string s)
        : leftExpr(ex1), rightExpr(ex2), op(s) {}

    ~AddSubExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *leftExpr;
    Expression *rightExpr;
    string op;
};
