#include "Type.h"

Type::Type(string type)
    : label(type)
{
    if (type == "int")
    {
        size = 4;
    }
    if (type == "char")
    {
        size = 1;
    }
    if (type == "int64_t")
    {
        size = 8;
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