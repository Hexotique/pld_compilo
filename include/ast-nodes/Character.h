#include <string>

#include "Expression.h"

using namespace std;

class Character : public Expression
{
public:
Character(Type *type, char c)
        : Expression(type), value(c) {}

    string buildIR(CFG *cfg);

protected:
    char value;
};