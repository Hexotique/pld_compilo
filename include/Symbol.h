#pragma once

#include <string>

#include "Type.h"

using namespace std;

class Type;

class Symbol
{
public:
    Symbol(Type *t, string id, int idx)
        : type(t), identifier(id), index(idx) {};

    string get_identifier();

    int get_index();

    Type *get_type();

protected:
    Type *type;
    string identifier;
    int index;

    friend class SymbolTable;
};