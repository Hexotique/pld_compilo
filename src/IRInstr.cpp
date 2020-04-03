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
    case 1:
        operation = "movb";
        break; 
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
    case 1:
        operation = "movb";
        reg = "%al";
        break; 
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
    string sub_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        sub_op = "subl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        sub_op = "subq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << sub_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void MultInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string mul_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        mul_op = "imull";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        mul_op = "imulq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << mul_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void DivInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string div_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        div_op = "idivl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        div_op = "idivq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\tcltd" << endl;
    o << "\t" << div_op << "\t" << source_2 << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void AndInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string and_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        and_op = "andl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        and_op = "andq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << and_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void OrInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string or_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        or_op = "orl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        or_op = "orq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << or_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}

void XOrInstr::gen_asm(ostream &o)
{
    string mov_op = "";
    string xor_op = "";
    string reg = "";

    switch (t->get_size())
    {
    case 4:
        mov_op = "movl";
        xor_op = "xorl";
        reg = "%eax";
        break;
    case 8:
        mov_op = "movq";
        xor_op = "xorq";
        reg = "%rax";
        break;
    default:
        break;
    }

    o << "\t" << mov_op << "\t" << source_1 << ", " << reg << endl;
    o << "\t" << xor_op << "\t" << source_2 << ", " << reg << endl;
    o << "\t" << mov_op << "\t" << reg << ", " << destination << endl;
}
