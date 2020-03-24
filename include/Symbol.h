#pragma once

#include <string>

#include "Type.h"

using namespace std;

class Type;

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
    Symbol(Type *t, string id, int idx)
        : type(t), identifier(id), index(idx) {};

    string get_identifier();

    int get_index();

protected:
    Type *type;
    string identifier;
    int index;

    friend class SymbolTable;
};