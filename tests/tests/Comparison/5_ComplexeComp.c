int main()
{
    int a=1>2;
    int b=1<2;
    int c=(a==b)<a;
    int d=a==(b>a);
    d=(d!=c);
    return d;
}

