#include "symbolTable.h"

void Symbol::print()
{
}

SymbolTable::SymbolTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        head[i] = NULL;
    };
}

int SymbolTable::hashf(string id)
{
    int sum = 0;
    for (int i = 0; i < id.length(); i++)
    {
        sum += id[i];
    }
    return sum % 100;
}

bool SymbolTable::insert(string id, string scope, string type, int line)
{
    int index = hashf(id);
    Symbol *s = new Symbol(id, scope, type, line);

    if (head[index] == NULL)
    {
        head[index] = s;
        return true;
    }
    else
    {
        Symbol *start = head[index];
        while (start->next != NULL)
        {
            start = start->next;
        }
        start->next = s;
        return true;
    
    return false;
}

string SymbolTable::find(string id)
{
    int index = hashf(id);
    Symbol *start = head[index];

    if(start == NULL) {

    }
}