// cesun, 9/1/20 3:10 AM.

#include <cstdio>

//https://stackoverflow.com/questions/370283/why-cant-i-have-a-non-integral-static-const-member-in-a-class

struct Foo {
    static const int x0 = 42; // compile time substitution; non-existent at runtime; can't take addr of x
    // constexpr in object declaration implies const
    static constexpr int x1 = 99; // has addr; is a runtime object;
    //static const int xArr0[4]{42, 42, 42, 42};
    static constexpr int xArr1[4]{42, 43, 44, 45}; // const is part of the type `const int`, constexpr is an attribute of its value {42,42,42,42};
};

int main() {
    printf("%lu\n", sizeof(Foo)); // 1, instance has no data member; but what's that 1?
    printf("%lu\n", sizeof(Foo::xArr1)); // 16
    //printf("%p\n", &Foo::x0); //undefined reference to `Foo::x0'
    printf("%p\n", Foo::xArr1);
    printf("%d\n", Foo::xArr1[2]);
    printf("%p\n", &Foo::x1); // neat
}
