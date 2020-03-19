#pragma once

#include <string>

#include "Type.h"

using namespace std;

enum class SymbolScope
{
    global,
    function,
    loop,
    conditional,
    anonymous
};

class Symbol
{
public:
    Symbol(SymbolScope sts, string st, string id, string sn, unsigned int nl, unsigned int ln)
        : scope_type(sts), type(st), identifier(id), scope_name(sn), nesting_level(nl), line_num(ln) {};

protected:
    SymbolScope scope_type;

    Type type;

    string identifier;
    string scope_name;

    unsigned int nesting_level;
    unsigned int line_num;

    friend class SymbolTable;
};