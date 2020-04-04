#include <string>

#include "Expression.h"

using namespace std;

class Var : public Expression
{
public:
    Var(string id)
        : identifier(id) {}

    string buildIR(CFG *cfg);

protected:
    string identifier;
};