int f(int a) {
    if (a == 4)
        return a;
    else
        return f(a + 1);
}

int main() {
    return f(2);
}