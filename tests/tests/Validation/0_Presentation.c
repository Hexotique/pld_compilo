int f(int a);

int main()
{
    int b = 3;
    int c = 2;
    int e = f(b);
    char k = 'k'; // c'est un k

    {
        int b = 7;
        e = b;
    }

    /*
            commentaire +sieurs lignes
        */

    if (e == 6)
        if (c == 2)
            putchar('k');
        else
            putchar('b');
    else if (e >= 7)
    {
        e = 100;
    }
    else 
        if (!(k <= 'k'))
        {
            k = k + 1;
        }
    else
        putchar('a');

    c = 100 + k * (b + e);

    while (e != 100)
    {
        e = e + 1;
    }

    for (int i = 0; i < 10; i = i + 1)
    {
        k = k + 1;
    }
    putchar(k);
    return (c | k) ^ 3;
}

int f(int a)
{
    if (a == 6)
        return a;
    else
        return f(a + 1);
}