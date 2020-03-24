#include "ASTNode.h"

class CFG;

class Statement : public ASTNode
{
public:
    virtual void buildIR(CFG *) = 0;

protected:
};