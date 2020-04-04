int main() {
    int a = 1;
    int b;
    {
        int a = 2;
        b = a + 2;
    }
    return b;
}