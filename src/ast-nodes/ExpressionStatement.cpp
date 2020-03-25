#include "ExpressionStatement.h"
#include "Expression.h"
#include "CFG.h"

string ExpressionStatement::buildIR(CFG *cfg)
{
    expression->buildIR(cfg);
    return "";
}