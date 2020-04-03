#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BasicBlock;
class CFG;
class Type;

//! The class for one 3-address instruction
class IRInstr
{

public:
    /** The instructions themselves -- feel free to subclass instead */
    typedef enum
    {
        ldconst,
        copy,
        add,
        sub,
        mul,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_lt,
        cmp_le
    } Operation;

    IRInstr(Type *type)
        : t(type) {}

    void set_block(BasicBlock *block);

    virtual void gen_asm(ostream &o) = 0;

protected:
    BasicBlock *bb;
    Type *t;
};

class LdConstInstr : public IRInstr
{
public:
    LdConstInstr(Type *type, string dest, string v)
        : IRInstr(type), destination(dest), value(v){};

    void gen_asm(ostream &o);

protected:
    string destination;
    string value;
};

class CopyInstr : public IRInstr
{
public:
    CopyInstr(Type *type, string dest, string src)
        : IRInstr(type), destination(dest), source(src) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source;
};

class AddInstr : public IRInstr
{
public:
    AddInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class SubInstr : public IRInstr
{
public:
    SubInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class MultInstr : public IRInstr
{
public:
    MultInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class DivInstr : public IRInstr
{
public:
    DivInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class AndInstr : public IRInstr
{
public:
    AndInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class OrInstr : public IRInstr
{
public:
    OrInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class XOrInstr : public IRInstr
{
public:
    XOrInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class SupInstr : public IRInstr
{
public:
    SupInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class InfInstr : public IRInstr
{
public:
    InfInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class EquInstr : public IRInstr
{
public:
    EquInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class InequInstr : public IRInstr
{
public:
    InequInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};

class SupEquInstr : public IRInstr
{
public:
    SupEquInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};


class InfEquInstr : public IRInstr
{
public:
    InfEquInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type), destination(dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string destination;
    string source_1;
    string source_2;
};
