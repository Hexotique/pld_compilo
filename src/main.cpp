#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "../antlr4-src/ifccLexer.h"
#include "../antlr4-src/ifccParser.h"
#include "../antlr4-src/ifccBaseVisitor.h"
#include "visitor.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv) {
  stringstream in;
  if (argn==2) {
     ifstream lecture(argv[1]);
     in << lecture.rdbuf();
  }
  ANTLRInputStream input(in.str());
  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
//  for (auto token : tokens.getTokens()) {
//    std::cout << token->toString() << std::endl;
//  }

  ifccParser parser(&tokens);
  tree::ParseTree* tree = parser.axiom();

  Visitor visitor;
  visitor.visit(tree);

  return 0;
}
