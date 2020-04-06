#include <string>

#include "ASTNode.h"

class CFG;
class Expression;
class Statement;

using namespace std;

class ElseIf : public ASTNode
{
public:
    ElseIf(Expression *e, Statement *s)
        : expr(e), thenStmt(s){};

    string buildIR(CFG *cfg);

protected:
    Expression *expr;
    Statement *thenStmt;
};