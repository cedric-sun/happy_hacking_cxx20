// cesun, 9/1/20 2:20 AM.

#include <cstdio>

struct Foo {
    static const int x = 42;
};

int main() {
    printf("%lu\n", sizeof(Foo));
    printf("%d\n", Foo::x);
    printf("%p\n", &(Foo::x));//wow... can't take address here: (linker) undefined reference to `Foo::x'
}