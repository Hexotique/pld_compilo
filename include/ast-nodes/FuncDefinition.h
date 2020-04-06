#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"

using namespace std;

class Declaration;
class Type;
class Block;
class FuncDeclaration;

class FuncDefinition : public ASTNode
{
public:
    FuncDefinition(FuncDeclaration *fd, Block *b)
        : fctDec(fd), fctBlock(b) {}

    FuncDeclaration *getFctDec();

    string buildIR(CFG *cfg);

protected:
    FuncDeclaration *fctDec;
    Block *fctBlock;
};