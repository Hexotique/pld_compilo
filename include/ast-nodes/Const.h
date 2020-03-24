#include "Expression.h"

class Const : public Expression
{
public:
    Const(int c)
        : value(c) {}

    void buildIR(CFG *cfg);

protected:
    int value;
};