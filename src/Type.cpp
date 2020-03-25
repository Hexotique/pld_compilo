#include "Type.h"

Type::Type(string type)
    : label(type)
{
    if (type == "int")
    {
        size = 4;
    }
}

string Type::get_label()
{
    return label;
}

int Type::get_size()
{
    return size;
}