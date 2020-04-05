#include "BlockStatement.h"
#include "CFG.h"
#include "Block.h"

string BlockStatement::buildIR(CFG *cfg)
{
    return block->buildIR(cfg);
}