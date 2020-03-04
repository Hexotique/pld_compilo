#include "visitor.h"

antlrcpp::Any Visitor::visitAxiom(ifccParser::AxiomContext *ctx) {
	return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *ctx) {
	int retval = stoi(ctx->CONST()->getText());
	std::cout << ".globl main\n"
		" main: \n"
		" 	movl 	$" << retval << ", %eax\n"
		" 	ret\n";
	return 0;
}
