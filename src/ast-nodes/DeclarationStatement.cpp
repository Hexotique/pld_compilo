#include "DeclarationStatement.h"
#include "CFG.h"
#include "Declaration.h"
#include "Type.h"

string DeclarationStatement::buildIR(CFG *cfg)
{
    for (Declaration *d : declarations)
    {
        d->buildIR(cfg);
    }
    return "";
}