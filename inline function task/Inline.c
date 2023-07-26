// "Copyright [2023] Muhammad Faizan"
#include <stdio.h>

// static inline function
static inline int mult(int x, int y) {
    return x * y;
}

int main() {
    int a = 37, b = 13;
    int product = mult(a, b);

    printf("Product of %d and %d is = %d\n", a, b, product);

    return 0;
}
