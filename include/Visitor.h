
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once

#include "antlr4-runtime.h"
#include "ifccVisitor.h"
#include "Program.h"
#include "Function.h"

/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class Visitor : public ifccVisitor
{
public:
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) override;

    virtual antlrcpp::Any visitFunction(ifccParser::FunctionContext *context) override;

    virtual antlrcpp::Any visitFuncParams(ifccParser::FuncParamsContext *context) override;

    virtual antlrcpp::Any visitParamList(ifccParser::ParamListContext *context) override;

    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

    virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

    virtual antlrcpp::Any visitStatement(ifccParser::StatementContext *context) override;

    virtual antlrcpp::Any visitReturnStatement(ifccParser::ReturnStatementContext *context) override;

    virtual antlrcpp::Any visitExpression(ifccParser::ExpressionContext *context) override;
};
