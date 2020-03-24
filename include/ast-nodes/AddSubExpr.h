#include <string>

#include "Expression.h"

using namespace std;

class AddSubExpr : public Expression
{
public:
    AddSubExpr(Expression *ex1, Expression *ex2, string symb)
        : exp1(ex1), exp2(ex2), symbol(symb) {}

    ~AddSubExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *exp1;
    Expression *exp2;
    string symbol;
};
