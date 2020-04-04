#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Symbol;
class Type;

class SymbolTable
{
public:
    SymbolTable();

    Symbol *insert(string label, Type *type);

    Symbol *lookup(string id);

    Symbol *local_lookup(string id);

    void enter_scope();

    void exit_scope();

    int get_cur_index();

    void show();

protected:
    int cur_index;
    vector<map<string, Symbol *>> st;
};