#include <string>
#include <vector>

#include "Statement.h"

class CFG;
class Expression;
class ElseIf;

using namespace std;

class IfStatement : public Statement
{
public:
    IfStatement(Expression *e, Statement *ts, vector<ElseIf *> ei, Statement *es)
        : expr(e), thenStmt(ts), elseIfs(ei), elseStmt(es){};

    string buildIR(CFG *cfg);

protected:
    Expression *expr;
    Statement *thenStmt;
    vector<ElseIf *> elseIfs;
    Statement *elseStmt;
};