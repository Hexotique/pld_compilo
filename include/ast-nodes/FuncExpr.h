#include <string>
#include <set>
#include <vector>

#include "Expression.h"

using namespace std;

class FuncExpr : public Expression
{
public:
    const set<string> builtin_funcs = {"putchar"};

    FuncExpr(string fl, vector<Expression *> fp)
        : funcLabel(fl), funcParams(fp) {}

    ~FuncExpr() {}

    string buildIR(CFG *cfg);

protected:
    string funcLabel;
    vector<Expression *> funcParams;
};