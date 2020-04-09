#include "FuncExpr.h"
#include "FuncDeclaration.h"
#include "CFG.h"
#include "Symbol.h"
#include "Type.h"
#include "IRInstr.h"

string FuncExpr::buildIR(CFG *cfg)
{
    Symbol *s = cfg->create_temp_var(type);
    string dest = cfg->var_to_asm(s->get_identifier());

    vector<string> params;
    for (Expression *expr : funcParams)
    {
        params.push_back(cfg->var_to_asm(expr->buildIR(cfg)));
    }

    if (builtin_funcs.find(funcLabel) != builtin_funcs.end())
    {
        funcLabel += "@PLT";
    }

    if (cfg->get_global_funcs().count(funcLabel) == 0)
    {
        cerr << "warning: function '" << funcLabel << "' is not declared before usage." << endl; 
    }
    else if (cfg->get_global_funcs()[funcLabel]->getParams().size() != params.size())
    {
        cerr << "error: function '" << funcLabel << "' has no signature with " << params.size() << "parameters." << endl;
        exit(1); 
    }

    cfg->add_instruction(new CallInstr(type, funcLabel, dest, params));
    return s->get_identifier();
}