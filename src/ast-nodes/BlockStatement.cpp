#include "BlockStatement.h"
#include "CFG.h"
#include "Block.h"

string BlockStatement::buildIR(CFG *cfg)
{
    cfg->enter_scope();
    block->buildIR(cfg);
    cfg->exit_scope();
    return "";
}