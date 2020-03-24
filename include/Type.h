#pragma once

#include <string>

using namespace std;

class Type
{
public:
    Type(string type);

    string get_label();

    int get_size();

protected:
    string label;
    int size;
};