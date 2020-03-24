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
