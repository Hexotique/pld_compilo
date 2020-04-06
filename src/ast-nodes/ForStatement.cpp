#include "ForStatement.h"
#include "Expression.h"
#include "BasicBlock.h"
#include "CFG.h"

string ForStatement::buildIR(CFG *cfg)
{
    initialization->buildIR(cfg);

    BasicBlock *curr_block = cfg->get_current_block();

    BasicBlock *test_block = cfg->add_basic_block();
    BasicBlock *body_block = cfg->add_basic_block();
    BasicBlock *aftr_block = cfg->add_basic_block();

    aftr_block->set_exit_true(curr_block->get_exit_true());
    aftr_block->set_exit_false(curr_block->get_exit_false());

    curr_block->set_exit_true(test_block);

    test_block->set_exit_true(body_block);
    test_block->set_exit_false(aftr_block);

    body_block->set_exit_true(test_block);

    cfg->set_current_block(test_block);
    test_block->set_test_var_name(condition->buildIR(cfg));

    cfg->set_current_block(body_block);
    statement->buildIR(cfg);
    update->buildIR(cfg);

    cfg->set_current_block(aftr_block);
    return "";
}