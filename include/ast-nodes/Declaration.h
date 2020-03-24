#include <string>

#include "ASTNode.h"

using namespace std;

class Declaration : public ASTNode
{
public:
    Declaration(string typ, string id)
        : type(typ), identifier(id) {}
    ~Declaration() {}
    void buildIR(CFG *cfg);

protected:
    string type;
    string identifier;
};