int main() {
    int a = 6;
    int b = 0;
    if (b) {
        a = a + 2;
    } else if (a) {
        a = a * 2;
    } else {
        a = a - 2;
    }
    return a;
}