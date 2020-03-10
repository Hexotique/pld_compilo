#include <iostream>
#include <string>

#define TABLE_SIZE 100

using namespace std;

class Symbol
{
public:
    Symbol()
        : next(NULL){};

    Symbol(string key, string value, string t, int num)
        : identifier(key), scope(value), type(t), lineNum(num){};

    void print();

protected:
    string identifier, scope, type;
    int lineNum;
    Symbol *next;

    friend class SymbolTable;
};

class SymbolTable
{
public:
    SymbolTable();

    int hashf(string id);

    bool insert(string id, string scope, string type, int line);

    string find(string id);

    bool remove(string id);

    bool modify(string id, string scope, string type, int line);

protected:
    Symbol *head[TABLE_SIZE];
};