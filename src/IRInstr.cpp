#include "IRInstr.h"
#include "Type.h"

void IRInstr::set_block(BasicBlock *block)
{
    bb = block;
}

void LdConstInstr::gen_asm(ostream &o)
{
    string operation = "";
    switch (t->get_size())
    {
    case 4:
        operation = "movl";
        break;
    case 8:
        operation = "movq";
        break;
    default:
        break;
    }
    o << "\t" << operation << "\t$" << value << ", " << destination << endl;
}

void CopyInstr::gen_asm(ostream &o)
{
    string operation = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        operation = "movl";
        reg = "%eax";
        break;
    case 8:
        operation = "movq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << operation << "\t" << source << ", " << reg << endl;
    o << "\t" << operation << "\t" << reg << ", " << destination << endl;
}

void AddInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string add_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        add_op = "addl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        add_op = "addq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << add_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void SubInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string add_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        add_op = "subl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        add_op = "subq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << add_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}