#include <cstring>
#include "Visitor.h"
#include "Program.h"
#include "FuncDeclaration.h"
#include "FuncDefinition.h"
#include "Expression.h"
#include "Block.h"
#include "Type.h"
#include "Return.h"
#include "Const.h"
#include "Character.h"
#include "Assignment.h"
#include "AddSubExpr.h"
#include "BitExpr.h"
#include "CompExpr.h"
#include "NotExpr.h"
#include "Declaration.h"
#include "Definition.h"
#include "DeclarationStatement.h"
#include "ExpressionStatement.h"
#include "Var.h"
#include "MultDivExpr.h"
#include "BlockStatement.h"
#include "FuncExpr.h"
#include "ForStatement.h"
#include "WhileStatement.h"
#include "IfStatement.h"
#include "ElseIf.h"

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
    Program *prog = new Program();
    for (const auto f : context->function())
    {
        FuncDefinition *funct = visit(f);
        prog->addFunction(funct);
    }
    return prog;
}

antlrcpp::Any Visitor::visitFuncDeclaration(ifccParser::FuncDeclarationContext *context)
{
    string fname = context->IDENTIFIER()->getText();
    string rt = context->TYPE()->getText();
    vector<Declaration *> fparams = visit(context->funcParams());
    Type *retType = new Type(rt);

    return new FuncDeclaration(fname, retType, fparams);
}

antlrcpp::Any Visitor::visitFunction(ifccParser::FunctionContext *context)
{
    FuncDeclaration *fctDec = visit(context->funcDeclaration());
    Block *block = visit(context->block());
    return new FuncDefinition(fctDec, block);
}

antlrcpp::Any Visitor::visitFuncParams(ifccParser::FuncParamsContext *context)
{
    vector<Declaration *> fparams;
    for (const auto param : context->declaration())
    {
        fparams.push_back(visit(param));
    }
    return fparams;
}

antlrcpp::Any Visitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    Type *type = new Type(context->TYPE()->getText());
    string identifier = context->IDENTIFIER()->getText();

    return new Declaration(type, identifier);
}

antlrcpp::Any Visitor::visitBlock(ifccParser::BlockContext *context)
{
    Block *b = new Block();
    for (const auto s : context->statement())
    {
        Statement *stmt = visit(s);
        b->addStatement(stmt);
    }
    return b;
}

antlrcpp::Any Visitor::visitElif(ifccParser::ElifContext *context)
{
    Expression *expr = visit(context->expression());
    Statement *stmt = visit(context->statement());
    return new ElseIf(expr, stmt);
}

antlrcpp::Any Visitor::visitEl(ifccParser::ElContext *context)
{
    return (Statement *)visit(context->statement());
}

antlrcpp::Any Visitor::visitReturnStatement(ifccParser::ReturnStatementContext *context)
{
    Expression *expr = visit(context->expression());
    return (Statement *)new Return(expr->get_type(), expr);
}

antlrcpp::Any Visitor::visitDeclarationStatement(ifccParser::DeclarationStatementContext *context)
{
    vector<Declaration *> decs;
    Declaration *dec = visit(context->declaration());
    decs.push_back(dec);
    for (const auto id : context->IDENTIFIER())
    {
        decs.push_back(new Declaration(dec->get_type(), id->getText()));
    }
    return (Statement *)new DeclarationStatement(decs);
}

antlrcpp::Any Visitor::visitDefine(ifccParser::DefineContext *context)
{
    Declaration *dec = visit(context->declaration());
    Expression *expr = visit(context->expression());
    return (Statement *)new Definition(dec, expr);
}

antlrcpp::Any Visitor::visitDefinitionStatement(ifccParser::DefinitionStatementContext *context)
{
    return (Statement *)visit(context->define());
}

antlrcpp::Any Visitor::visitBlockStatement(ifccParser::BlockStatementContext *context)
{
    Block *block = visit(context->block());
    return (Statement *)new BlockStatement(block);
}

antlrcpp::Any Visitor::visitIfStatement(ifccParser::IfStatementContext *context)
{
    vector<ElseIf *> elifs;
    Expression *ifExpr = visit(context->expression());
    Statement *thenStmt = visit(context->statement());
    Statement *elseStmt = nullptr;

    for (const auto ei : context->elif ())
    {
        elifs.push_back(visit(ei));
    }

    if (context->el())
    {
        elseStmt = visit(context->el());
    }

    return (Statement *)new IfStatement(ifExpr, thenStmt, elifs, elseStmt);
}

antlrcpp::Any Visitor::visitForStatement(ifccParser::ForStatementContext *context)
{
    return 0;
}

antlrcpp::Any Visitor::visitWhileStatement(ifccParser::WhileStatementContext *context)
{
    Expression *expr = visit(context->expression());
    Statement *stmt = visit(context->statement());
    return (Statement *)new WhileStatement(expr, stmt);
}

antlrcpp::Any Visitor::visitExprStatement(ifccParser::ExprStatementContext *context)
{
    Expression *expr = visit(context->expression());
    return (Statement *)new ExpressionStatement(expr);
}

antlrcpp::Any Visitor::visitParExpr(ifccParser::ParExprContext *context)
{
    return (Expression *)visit(context->expression());
}

antlrcpp::Any Visitor::visitVarExpr(ifccParser::VarExprContext *context)
{
    return (Expression *)new Var(context->IDENTIFIER()->getText());
}

antlrcpp::Any Visitor::visitNotExpr(ifccParser::NotExprContext *context)
{
    Expression *expr = (Expression *)visit(context->expression());
    return (Expression *)new NotExpr(expr);
}

antlrcpp::Any Visitor::visitFuncExpr(ifccParser::FuncExprContext *context)
{
    string funcLabel = context->IDENTIFIER()->getText();
    vector<Expression *> params;
    for (const auto expr : context->expression())
    {
        params.push_back(visit(expr));
    }
    return (Expression *)new FuncExpr(funcLabel, params);
}

antlrcpp::Any Visitor::visitAddSubExpr(ifccParser::AddSubExprContext *context)
{
    string symb = context->ADD_SUB_OPERATOR()->getText();
    Expression *expr1 = (Expression *)visit(context->expression(0));
    Expression *expr2 = (Expression *)visit(context->expression(1));
    return (Expression *)new AddSubExpr(expr1, expr2, symb);
};

antlrcpp::Any Visitor::visitMultDivExpr(ifccParser::MultDivExprContext *context)
{
    string symb = context->MULT_DIV_OPERATOR()->getText();
    Expression *expr1 = (Expression *)visit(context->expression(0));
    Expression *expr2 = (Expression *)visit(context->expression(1));
    return (Expression *)new MultDivExpr(expr1, expr2, symb);
}

antlrcpp::Any Visitor::visitBitExpr(ifccParser::BitExprContext *context)
{
    string symb = context->BIT_OPERATOR()->getText();
    Expression *expr1 = (Expression *)visit(context->expression(0));
    Expression *expr2 = (Expression *)visit(context->expression(1));
    return (Expression *)new BitExpr(expr1, expr2, symb);
}

antlrcpp::Any Visitor::visitCompExpr(ifccParser::CompExprContext *context)
{
    string symb = context->COMP_OPERATOR()->getText();
    Expression *expr1 = (Expression *)visit(context->expression(0));
    Expression *expr2 = (Expression *)visit(context->expression(1));
    return (Expression *)new CompExpr(expr1, expr2, symb);
}

antlrcpp::Any Visitor::visitAssignExpr(ifccParser::AssignExprContext *context)
{
    string identifier = context->IDENTIFIER()->getText();
    Expression *e = visit(context->expression());
    return (Expression *)new Assignment(identifier, e);
};

antlrcpp::Any Visitor::visitConstExpr(ifccParser::ConstExprContext *context)
{
    long long value = strtoll(context->CONST()->getText().c_str(), NULL, 10);
    if (value > 2147483647)
    {
        return (Expression *)(new Const(new Type("int64"), value));
    }
    return (Expression *)(new Const(new Type("int"), value));
};

antlrcpp::Any Visitor::visitCharExpr(ifccParser::CharExprContext *context)
{
    string str = context->CHAR()->getText();
    char c;
    if (str.at(1) == '\\')
    {
        switch (str.at(2))
        {
        case '\'':
        case '\"':
        case '\?':
        case '\\':
            c = str.at(2);
            break;
        case 'a':
            c = '\a';
            break;
        case 'b':
            c = '\b';
            break;
        case 'e':
            c = '\e';
            break;
        case 'f':
            c = '\f';
            break;
        case 'n':
            c = '\n';
            break;
        case 'r':
            c = '\r';
            break;
        case 't':
            c = '\t';
            break;
        case 'v':
            c = '\v';
            break;
        }
    }
    else
    {
        c = str.at(1);
    }
    return (Expression *)(new Character(new Type("char"), c));
}