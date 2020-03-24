#include "Declaration.h"
#include "CFG.h"

Type *Declaration::get_type()
{
    return type;
}

string Declaration::get_identifier()
{
    return identifier;
}

string Declaration::buildIR(CFG *cfg)
{
    cfg->add_to_symbol_table(identifier, type);
    return "";
}