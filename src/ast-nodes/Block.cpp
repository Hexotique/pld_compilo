#include "Block.h"
#include "CFG.h"
#include "Statement.h"

void Block::addStatement(Statement *s)
{
    statements.push_back(s);
}

string Block::buildIR(CFG *cfg)
{
    cfg->enter_scope();
    for (Statement *s : statements)
    {
        s->buildIR(cfg);
    }
    cfg->exit_scope();

    return "";
}