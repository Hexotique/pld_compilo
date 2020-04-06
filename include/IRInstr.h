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
    IRInstr(Type *type, string d)
        : t(type), destination(d) {}

    void set_block(BasicBlock *block);

    string get_dest();

    Type *get_type();

    virtual void gen_asm(ostream &o) = 0;

protected:
    BasicBlock *bb;
    Type *t;
    string destination;
};

class LdConstInstr : public IRInstr
{
public:
    LdConstInstr(Type *type, string dest, string v)
        : IRInstr(type, dest), value(v){};

    void gen_asm(ostream &o);

protected:
    string value;
};

class CopyInstr : public IRInstr
{
public:
    CopyInstr(Type *type, string dest, string src)
        : IRInstr(type, dest), source(src) {}

    void gen_asm(ostream &o);

protected:
    string source;
};

class AddInstr : public IRInstr
{
public:
    AddInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class SubInstr : public IRInstr
{
public:
    SubInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class MultInstr : public IRInstr
{
public:
    MultInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class DivInstr : public IRInstr
{
public:
    DivInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class AndInstr : public IRInstr
{
public:
    AndInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class OrInstr : public IRInstr
{
public:
    OrInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class XOrInstr : public IRInstr
{
public:
    XOrInstr(Type *type, string dest, string src1, string src2)
        : IRInstr(type, dest), source_1(src1), source_2(src2) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
};

class CmpInstr : public IRInstr
{
public:
    CmpInstr(Type *type, string dest, string src1, string src2, string comp)
        : IRInstr(type, dest), source_1(src1), source_2(src2), comparison(comp) {}

    void gen_asm(ostream &o);

protected:
    string source_1;
    string source_2;
    string comparison;
};

class CallInstr : public IRInstr
{
public:
    CallInstr(Type *type, string fn, string dest, vector<string> ps)
        : IRInstr(type, dest), fname(fn), param_src(ps) {}

    void gen_asm(ostream &o);

protected:
    string fname;
    vector<string> param_src;
};
