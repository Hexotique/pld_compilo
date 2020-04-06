#include "Symbol.h"

string Symbol::get_identifier()
{
    return identifier;
}

int Symbol::get_index()
{
    return index;
}

Type *Symbol::get_type()
{
    return type;
}