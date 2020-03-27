#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "ifccLexer.h"
#include "ifccParser.h"
#include "ifccBaseVisitor.h"

#include "Visitor.h"
#include "ASTNode.h"
#include "Program.h"
#include "CFG.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
    stringstream in;
    if (argn == 2)
    {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
    }
    ANTLRInputStream input(in.str());
    ifccLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    /*
    for (auto token : tokens.getTokens())
    {
        std::cout << token->toString() << std::endl;
    }
    */
    ifccParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();

    if (lexer.getNumberOfSyntaxErrors() || parser.getNumberOfSyntaxErrors())
    {
        return 1;
    }

    Visitor visitor;
    Program *prog = visitor.visit(tree);
    vector<CFG *> cfgs = prog->buildIR();
    for (const auto cfg : cfgs)
    {
        cfg->gen_asm(cout);
    }

    return 0;
}
