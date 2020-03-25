/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)
 */
#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Function;
class BasicBlock;
class SymbolTable;
class Symbol;
class Type;
class IRInstr;

class CFG
{
public:
    CFG(Function *f);

    BasicBlock *get_current_block();

    void add_basic_block(BasicBlock *bb);

    void gen_asm(ostream &o);

    string var_to_asm(string identifier); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */

    void gen_asm_prologue(ostream &o);

    void gen_asm_epilogue(ostream &o);

    void enter_scope();

    void exit_scope();

    void add_instruction(IRInstr *instr);

    Symbol *add_to_symbol_table(string label, Type *t);

    Symbol *create_temp_var(Type *t);

    SymbolTable *get_symbol_table();

protected:
    Function *ast;

    BasicBlock *currentBlock;
    vector<BasicBlock *> blocks;

    SymbolTable *currentTable;
};
