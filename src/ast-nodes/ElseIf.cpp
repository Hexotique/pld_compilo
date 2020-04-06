#include "ElseIf.h"
#include "CFG.h"
#include "BasicBlock.h"
#include "Expression.h"
#include "Statement.h"

string ElseIf::buildIR(CFG *cfg)
{
    BasicBlock *curr_block = cfg->get_current_block(); //prev test

    BasicBlock *test_block = cfg->add_basic_block();
    BasicBlock *then_block = cfg->add_basic_block();

    curr_block->set_exit_false(test_block);

    test_block->set_exit_true(then_block);

    cfg->set_current_block(then_block);
    thenStmt->buildIR(cfg);

    cfg->set_current_block(test_block);
    test_block->set_test_var_name(expr->buildIR(cfg));

    return "";
}