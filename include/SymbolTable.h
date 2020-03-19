#include <string>
#include <list>

#include "Symbol.h"

#define TABLE_SIZE 100

using namespace std;

class SymbolTable
{
public:
    SymbolTable()
        : cur_nesting_level(0){};

    void enter_scope();

    void exit_scope();

    void insert(Symbol *s);

    Symbol *lookup(string id);

protected:
    SymbolScope cur_scope_type;
    unsigned int cur_nesting_level;
    string cur_scope_name;

    list<Symbol *> table[TABLE_SIZE];

private:
    int hashf(string id);
};