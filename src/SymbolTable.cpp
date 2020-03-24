#include "SymbolTable.h"
#include "Symbol.h"
#include "Type.h"

void SymbolTable::enter_scope()
{
    cur_nesting_level++;
}

void SymbolTable::exit_scope()
{
    cur_nesting_level--;
}

Symbol *SymbolTable::insert(string label, Type *type)
{
    cur_index += type->get_size();
    Symbol *s = new Symbol(type, label, cur_index);
    int index = hashf(s->identifier);
    table[index].push_front(s);
    return s;
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

int SymbolTable::get_cur_index()
{
    return cur_index;
}