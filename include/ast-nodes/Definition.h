#include <string>

#include "Statement.h"

using namespace std;

class Declaration;
class Expression;

class Definition : public Statement
{
public:
    Definition(Declaration *d, Expression *e)
        : dec(d), init(e) {}

    ~Definition() {}

    string buildIR(CFG *cfg);

protected:
    Declaration *dec;
    Expression *init;
};