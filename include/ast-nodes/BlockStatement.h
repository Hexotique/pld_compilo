#include <string>

#include "Statement.h"

class CFG;
class Block;

using namespace std;

class BlockStatement : public Statement
{
public:
    BlockStatement(Block *b)
        : block(b){};

    string buildIR(CFG *cfg);

protected:
    Block *block;
};