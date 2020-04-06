#pragma once

#include <vector>

using namespace std;

class FuncDefinition;
class FuncDeclaration;
class CFG;

class Program
{
public:
    Program() {}

    vector<FuncDefinition *> getFunctions();

    void addFunction(FuncDefinition *f);

    vector<CFG *> buildIR();

protected:
    vector<FuncDeclaration *> fctDecs;
    vector<FuncDefinition *> fctDefs;
};