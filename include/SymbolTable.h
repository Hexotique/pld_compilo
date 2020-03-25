#include <iostream>
#include <string>
#include <list>

#define TABLE_SIZE 100

using namespace std;

class Symbol;
class Type;

class SymbolTable
{
public:
    SymbolTable()
        : cur_nesting_level(0){};

    void enter_scope();

    void exit_scope();

    Symbol *insert(string label, Type *type);

    Symbol *lookup(string id);

    int get_cur_index();

    void show();

protected:
    unsigned int cur_nesting_level;
    string cur_scope_name;

    int cur_index;

    list<Symbol *> table[TABLE_SIZE];

private:
    int hashf(string id);
};