#pragma once

#include <string>

using namespace std;

class Type
{
public:
    Type(string type)
        : label(type) {}

protected:
    string label;
};