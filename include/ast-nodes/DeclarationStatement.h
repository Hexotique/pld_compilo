#include <vector>
#include <string>

#include "Statement.h"

class CFG;
class Declaration;

using namespace std;

class DeclarationStatement : public Statement
{
public:
    DeclarationStatement(vector<Declaration *> decs)
        : declarations(decs){};

    string buildIR(CFG *cfg);

protected:
    vector<Declaration *> declarations;
};