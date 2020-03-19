/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)
 */
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class ASTNode;
class BasicBlock;

class CFG
{
public:
    CFG(ASTNode *a)
        : ast(a){};

    void addBasicBlock(BasicBlock *bb);

    void gen_asm(ostream &o);
    
    string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
    
    void gen_asm_prologue(ostream &o);
    
    void gen_asm_epilogue(ostream &o);

protected:
    ASTNode *ast;

    BasicBlock *currentBlock;
    vector<BasicBlock *> blocks;
};
