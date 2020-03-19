#include "SymbolTable.h"

void SymbolTable::enter_scope()
{
    cur_nesting_level++;
}

void SymbolTable::exit_scope()
{
    cur_nesting_level--;
}

void SymbolTable::insert(Symbol *s)
{
    int index = hashf(s->identifier);
    table[index].push_front(s);
}

Symbol *SymbolTable::lookup(string id)
{
    int index = hashf(id);
    for (const auto s : table[index])
    {
        if (s->identifier == id)
        {
            return s;
        }
    }
    return nullptr;
}

int SymbolTable::hashf(string id)
{
    int sum = 0;
    for (int i = 0; i < id.length(); i++)
    {
        sum += id[i];
    }
    return sum % TABLE_SIZE;
}