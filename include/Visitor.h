
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once

#include "antlr4-runtime.h"
#include "ifccVisitor.h"

/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class Visitor : public ifccVisitor
{
public:
    antlrcpp::Any visitProg(ifccParser::ProgContext *context) override;

    antlrcpp::Any visitFunction(ifccParser::FunctionContext *context) override;

    antlrcpp::Any visitFuncParams(ifccParser::FuncParamsContext *context) override;

    antlrcpp::Any visitParamList(ifccParser::ParamListContext *context) override;

    antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

    antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

    antlrcpp::Any visitReturnStatement(ifccParser::ReturnStatementContext *context) override;

    antlrcpp::Any visitExprStatement(ifccParser::ExprStatementContext *context) override;

    antlrcpp::Any visitParExpr(ifccParser::ParExprContext *context) override;

    antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *context) override;

    antlrcpp::Any visitAssignExpr(ifccParser::AssignExprContext *context) override;

    antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *context) override;

};
