#include <stdint.h>

int64_t toto(int64_t a) {
    return a;
}

int bobo(int b) {
    return toto(b);
}

int main() {
    int x = 1;
    int y = 2;
    int64_t z = 3;
    int a = 64;
    y = toto(6);    
    return putchar(100);
}

