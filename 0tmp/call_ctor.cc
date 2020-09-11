// cesun, 9/2/20 2:33 PM.

#include <cstdio>

struct Foo {
    // don't provide user-defined constructor!
    // doing so preventing the struct from being a single aggregate,
    // thus breaks the designated-initializer-clause
    int x;
};

int main() {
    Foo y = {.x=24};
    printf("%d\n", y.x);
}