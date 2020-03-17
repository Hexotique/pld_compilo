#include <string>

using namespace std;

enum class SymbolTableScope
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
    Symbol(){};

    Symbol(SymbolTableScope sts, string id, string sn, unsigned int nl, unsigned int ln)
        : scope_type(sts), identifier(id), scope_name(sn), nesting_level(nl), line_num(ln) {};

protected:
    SymbolTableScope scope_type;

    string identifier;
    string scope_name;

    unsigned int nesting_level;
    unsigned int line_num;

    friend class SymbolTable;
};