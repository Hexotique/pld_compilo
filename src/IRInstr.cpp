#include "IRInstr.h"
#include "Type.h"

void IRInstr::set_block(BasicBlock *block)
{
    bb = block;
}

void LdConstInstr::gen_asm(ostream &o)
{
    string operation = "";
    if (t->get_size() == 4)
    {
        operation = "movl";
    }
    o << "\t" << operation << "\t$" << value << ", " << destination << endl;
}

void CopyInstr::gen_asm(ostream &o)
{
    string operation = "";
    if (t->get_size() == 4)
    {
        operation = "movl";
    }
    o << "\t" << operation << "\t" << source << ", %eax" << endl;
    o << "\t" << operation << "\t%eax, " << destination << endl;
}