#include <vector>
#include <string>

#include "Expression.h"

using namespace std;

class Assignment : public Expression
{
public:
    Assignment(string id, Expression *e)
        : identifier(id), expr(e) {}

    string buildIR(CFG * cfg);

protected:
    string identifier;
    Expression *expr;
};