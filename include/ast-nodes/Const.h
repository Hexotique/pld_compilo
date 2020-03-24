#include <string>

#include "Expression.h"

using namespace std;

class Const : public Expression
{
public:
    Const(Type *type, int c)
        : Expression(type), value(c) {}

    string buildIR(CFG *cfg);

protected:
    int value;
};