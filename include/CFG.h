/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)
 */
#pragma once

#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FuncDefinition;
class FuncDeclaration;
class BasicBlock;
class SymbolTable;
class Symbol;
class Type;
class IRInstr;

class CFG
{
public:
    const vector<string> param_reg_64 = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
    const vector<string> param_reg_32 = {"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};
    const vector<string> param_reg_8 = {"%dil", "%sil", "%dl", "%cl", "%r8b", "%r9b"};

    CFG(FuncDefinition *f, map<string, FuncDeclaration *> gs);

    BasicBlock *get_current_block();

    void set_current_block(BasicBlock *block);

    SymbolTable *get_sym_tab();

    BasicBlock *add_basic_block();

    void gen_asm(ostream &o);

    void gen_asm_prologue(ostream &o);

    void gen_asm_epilogue(ostream &o);

    void enter_scope();

    void exit_scope();

    void add_instruction(IRInstr *instr);

    Symbol *add_to_symbol_table(string label, Type *type);

    Symbol *create_temp_var(Type *type);

    string var_to_asm(string identifier);

    Type *get_var_type(string identifier);

    string gen_block_label();

    map<string, FuncDeclaration *> get_global_funcs();

protected:
    FuncDefinition *ast;

    BasicBlock *currentBlock;
    vector<BasicBlock *> blocks;

    map<string, FuncDeclaration *> globalFuncs;
    SymbolTable *symTab;
    int tmp_var_count;
};