#include "WhileStatement.h"
#include "CFG.h"
#include "BasicBlock.h"
#include "Expression.h"
#include "IRInstr.h"

string WhileStatement::buildIR(CFG *cfg)
{
    BasicBlock *curr_block = cfg->get_current_block();

    BasicBlock *test_block = cfg->add_basic_block();
    BasicBlock *body_block = cfg->add_basic_block();
    BasicBlock *aftw_block = cfg->add_basic_block();

    aftw_block->set_exit_true(curr_block->get_exit_true());
    aftw_block->set_exit_false(curr_block->get_exit_false());

    curr_block->set_exit_true(test_block);

    test_block->set_exit_true(body_block);
    test_block->set_exit_false(aftw_block);

    body_block->set_exit_true(test_block);

    cfg->set_current_block(test_block);
    test_block->set_test_var_name(expr->buildIR(cfg));

    cfg->set_current_block(body_block);
    stmt->buildIR(cfg);

    cfg->set_current_block(aftw_block);
    return "";
}