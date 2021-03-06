
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

    antlrcpp::Any visitFuncDeclaration(ifccParser::FuncDeclarationContext *context) override;

    antlrcpp::Any visitFunction(ifccParser::FunctionContext *context) override;

    antlrcpp::Any visitFuncParams(ifccParser::FuncParamsContext *context) override;

    antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

    antlrcpp::Any visitDefine(ifccParser::DefineContext *context) override;

    antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

    antlrcpp::Any visitElif(ifccParser::ElifContext *context) override;

    antlrcpp::Any visitEl(ifccParser::ElContext *context) override;

    antlrcpp::Any visitInitExpr(ifccParser::InitExprContext *context) override;

    antlrcpp::Any visitCondExpr(ifccParser::CondExprContext *context) override;

    antlrcpp::Any visitIncrExpr(ifccParser::IncrExprContext *context) override;

    antlrcpp::Any visitDeclarationStatement(ifccParser::DeclarationStatementContext *context) override;

    antlrcpp::Any visitReturnStatement(ifccParser::ReturnStatementContext *context) override;

    antlrcpp::Any visitDefinitionStatement(ifccParser::DefinitionStatementContext *context) override;

    antlrcpp::Any visitBlockStatement(ifccParser::BlockStatementContext *context) override;

    antlrcpp::Any visitIfStatement(ifccParser::IfStatementContext *context) override;

    antlrcpp::Any visitForStatement(ifccParser::ForStatementContext *context) override;

    antlrcpp::Any visitWhileStatement(ifccParser::WhileStatementContext *context) override;

    antlrcpp::Any visitExprStatement(ifccParser::ExprStatementContext *context) override;

    antlrcpp::Any visitParExpr(ifccParser::ParExprContext *context) override;

    antlrcpp::Any visitNotExpr(ifccParser::NotExprContext *context) override;

    antlrcpp::Any visitFuncExpr(ifccParser::FuncExprContext *context) override;

    antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *context) override;

    antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *context) override;

    antlrcpp::Any visitCharExpr(ifccParser::CharExprContext *context) override;

    antlrcpp::Any visitMultDivExpr(ifccParser::MultDivExprContext *context) override;

    antlrcpp::Any visitBitExpr(ifccParser::BitExprContext *context) override;

    antlrcpp::Any visitCompExpr(ifccParser::CompExprContext *context) override;

    antlrcpp::Any visitAssignExpr(ifccParser::AssignExprContext *context) override;

    antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *context) override;
};
