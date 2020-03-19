#include "Visitor.h"

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
    Program *prog = new Program();
    for (const auto f : context->function())
    {
        Function *funct = (Function *)visit(f);
        prog->addFunction(funct);
    }
    return (ASTNode *)prog;
}

antlrcpp::Any Visitor::visitFunction(ifccParser::FunctionContext *context)
{
    string fname = context->IDENTIFIER()->getText();
    string retType = context->TYPE()->getText();
    return new Function(fname, retType);
}

antlrcpp::Any Visitor::visitFuncParams(ifccParser::FuncParamsContext *context) { return 0; }

antlrcpp::Any Visitor::visitParamList(ifccParser::ParamListContext *context) { return 0; }

antlrcpp::Any Visitor::visitDeclaration(ifccParser::DeclarationContext *context) { return 0; }

antlrcpp::Any Visitor::visitBlock(ifccParser::BlockContext *context) { return 0; }

antlrcpp::Any Visitor::visitStatement(ifccParser::StatementContext *context) { return 0; }

antlrcpp::Any Visitor::visitReturnStatement(ifccParser::ReturnStatementContext *context) { return 0; }

antlrcpp::Any Visitor::visitExpression(ifccParser::ExpressionContext *context) { return 0; }