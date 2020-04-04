#include <string>

#include "Expression.h"

using namespace std;

class NotExpr : public Expression
{
public:
    NotExpr(Expression *ex)
        : expr(ex){}

    ~NotExpr() {}

    string buildIR(CFG *cfg);

protected:
    Expression *expr;
};
