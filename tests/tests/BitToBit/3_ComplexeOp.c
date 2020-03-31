int main()
{
    int a, b, c, d;
    a = 5;
    b = 7;
    c = (a&b)|8^a;
    d = (a|b^c)&9;
    return d;
}
