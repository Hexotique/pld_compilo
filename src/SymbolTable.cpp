#include "SymbolTable.h"
#include "Symbol.h"
#include "Type.h"

SymbolTable::SymbolTable()
    : cur_index(0)
{
    st.push_back(map<string, Symbol *>());
}

Symbol *SymbolTable::insert(string label, Type *type)
{
    if (local_lookup(label) != nullptr)
    {
        cerr << "error: redeclaration of '" << label << "' variable" << endl;
        exit(1);
    }
    cur_index += type->get_size();
    Symbol *s = new Symbol(type, label, cur_index);
    st.back().insert(make_pair(s->get_identifier(), s));
    return s;
}

Symbol *SymbolTable::lookup(string id)
{
    for (auto it = st.rbegin(); it != st.rend(); it++)
    {
        if ((*it).count(id))
        {
            return (*it)[id];
        }
    }
    return nullptr;
}

Symbol *SymbolTable::local_lookup(string id)
{
    map<string, Symbol *> cur_map = st.back();
    if (cur_map.count(id))
    {
        return cur_map[id];
    }
    return nullptr;
}

void SymbolTable::enter_scope()
{
    st.push_back(map<string, Symbol *>());
}

void SymbolTable::exit_scope()
{
    st.pop_back();
}

int SymbolTable::get_cur_index()
{
    return cur_index;
}

void SymbolTable::show()
{
    for (auto cur_map : st)
    {
        for (auto &x : cur_map)
        {
            cout << x.first << " " << x.second->get_index() << endl;
        }
        cout << "===" << endl;
    }
}