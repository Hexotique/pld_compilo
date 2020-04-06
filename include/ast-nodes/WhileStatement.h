#include <string>

#include "Statement.h"

class CFG;
class Expression;

using namespace std;

class WhileStatement : public Statement
{
public:
    WhileStatement(Expression *e, Statement *s)
        : expr(e), stmt(s){};

    string buildIR(CFG *cfg);

protected:
    Expression *expr;
    Statement *stmt;
};