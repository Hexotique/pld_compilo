#include "Visitor.h"
#include "Program.h"
#include "Function.h"
#include "Expression.h"
#include "Block.h"
#include "Type.h"
#include "Return.h"
#include "Const.h"
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

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
    Program *prog = new Program();
    for (const auto f : context->function())
    {
        Function *funct = (Function *)visit(f);
        prog->addFunction(funct);
    }
    return prog;
}

antlrcpp::Any Visitor::visitFunction(ifccParser::FunctionContext *context)
{
    string fname = context->IDENTIFIER()->getText();
    string rt = context->TYPE()->getText();

    Type *retType = new Type(rt);
    Block *block = (Block *)visit(context->block());
    return new Function(fname, retType, block);
}

antlrcpp::Any Visitor::visitFuncParams(ifccParser::FuncParamsContext *context) { return 0; }

antlrcpp::Any Visitor::visitParamList(ifccParser::ParamListContext *context) { return 0; }

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

antlrcpp::Any Visitor::visitReturnStatement(ifccParser::ReturnStatementContext *context)
{
    Expression *expr = visit(context->expression());
    return (Statement *)new Return(new Type("int"), expr);
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

antlrcpp::Any Visitor::visitDefinitionStatement(ifccParser::DefinitionStatementContext *context)
{
    Declaration *dec = visit(context->declaration());
    Expression *expr = visit(context->expression());
    return (Statement *)new Definition(dec, expr);
}

antlrcpp::Any Visitor::visitExprStatement(ifccParser::ExprStatementContext *context)
{
    Expression *expr = visit(context->expression());
    return (Statement *)new ExpressionStatement(expr);
}

antlrcpp::Any Visitor::visitParExpr(ifccParser::ParExprContext *context)
{
    return (Expression *)visit(context->expression());
};

antlrcpp::Any Visitor::visitVarExpr(ifccParser::VarExprContext *context)
{
    return (Expression *)new Var(context->IDENTIFIER()->getText());
}

antlrcpp::Any Visitor::visitNotExpr(ifccParser::NotExprContext *context)
{
    Expression *expr= (Expression *)visit(context->expression());
    return (Expression *)new NotExpr(expr);
};

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
    return (Expression *)(new Const(new Type("int"), stoi(context->CONST()->getText())));
};
