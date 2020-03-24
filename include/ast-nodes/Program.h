#pragma once

#include <vector>

using namespace std;

class Function;
class CFG;

class Program
{
public:
    Program() {}

    vector<Function *> getFunctions();

    void addFunction(Function *f);

    vector<CFG *> buildIR();

protected:
    vector<Function *> fcts;
};