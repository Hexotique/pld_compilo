#include "IfStatement.h"
#include "CFG.h"
#include "BasicBlock.h"
#include "Expression.h"
#include "ElseIf.h"

string IfStatement::buildIR(CFG *cfg)
{
    BasicBlock *curr_block = cfg->get_current_block();

    BasicBlock *test_block = cfg->add_basic_block();
    BasicBlock *then_block = cfg->add_basic_block();
    BasicBlock *aftr_block = cfg->add_basic_block();

    aftr_block->set_exit_true(curr_block->get_exit_true());
    aftr_block->set_exit_false(curr_block->get_exit_false());

    curr_block->set_exit_true(test_block);

    test_block->set_exit_true(then_block);
    test_block->set_exit_false(aftr_block);

    then_block->set_exit_true(aftr_block);

    cfg->set_current_block(then_block);
    thenStmt->buildIR(cfg);

    cfg->set_current_block(test_block);
    test_block->set_test_var_name(expr->buildIR(cfg));

    int elifCount = elseIfs.size();

    if (elifCount)
    {
        elseIfs.front()->buildIR(cfg);
        BasicBlock *elif_block = cfg->get_current_block();
        test_block->set_exit_false(elif_block);
        elif_block->get_exit_true()->set_exit_true(aftr_block);
        test_block = elif_block;

        for (int i = 1; i < elifCount; i++)
        {
            elseIfs[i]->buildIR(cfg);
            elif_block = cfg->get_current_block();
            test_block->set_exit_false(elif_block);
            elif_block->get_exit_true()->set_exit_true(aftr_block);
            test_block = elif_block;
        }
    }

    if (elseStmt)
    {
        BasicBlock *else_block = cfg->add_basic_block();
        test_block->set_exit_false(else_block);
        cfg->set_current_block(else_block);
        elseStmt->buildIR(cfg);
    }

    cfg->set_current_block(aftr_block);
    return "";
}