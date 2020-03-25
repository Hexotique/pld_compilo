#include <string>

#include "ASTNode.h"

using namespace std;

class Type;

class Declaration : public ASTNode
{
public:
    Declaration(Type *t, string id)
        : type(t), identifier(id) {}

    ~Declaration() {}
    
    Type *get_type();

    string get_identifier();

    string buildIR(CFG *cfg);

protected:
    Type *type;
    string identifier;
};