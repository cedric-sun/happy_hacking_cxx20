// cesun, 8/31/20 10:01 PM.

#include <cstdio>

/**
 * Most static data member are pure declaration. To define the entity introduced, write
 * definition outside the class definition.
 *
 * The only exception is static const data member with initializer in class definition.
 */
struct Foo {
    int x; // DEFINES a non-static data member

    static int sx0; // DECLARES a static data member of complete type int. NO DEFINITION.
    // static int sx1 = 42; //error: ISO C++ forbids in-class initialization of non-const static member ‘Foo::sx1’
    static int sx2; // DECLARES a static data member of complete type int.

    static const int scx0; // DECLARES a static const data member of complete type const int. NO DEFINITION.
    static const int scx1 = 142; // (cannot be odr-used) DECLARES a static const data member of complete type const int. STILL NO DEFINITION. works like macros (compile time substitution); such in-class init of static data member IS ONLY LEGAL for type `const (int|long|<any integral type>...)`;
    // static const double scxDouble = 3.1415; // error: ‘constexpr’ needed for in-class initialization of static data member ‘const double Foo::scxDouble’ of non-integral type [-fpermissive]
    static const int scx2 = 199; // (can be odr-used) DECLARES a static const data member of complete type const int. HAS DEFINITION BELOW, meaning it has storage at runtime, its address can be taken.
    static const int scx3; // DECLARES a static const data member of complete type const int. Definition provided outside the class definition in the same way of a non-const int, but must with initializer. Has storage at runtime;

    static int sArr0[]; // DECLARES a static data member of incomplete type int[], NO DEFINITION.
    static int sArr1[]; // DECLARES a static data member of incomplete type int[], if this `struct Foo` definition is in a header file, the including client code won't know length of the array, thus cannot `sizeof()`; but as long as it has definition, everything works fine (you can `Foo::sArr1[0],Foo::sArr1[1],...` and get those value ... though index out of bound at your own risk.... ).
    static int sArr2[12]; // DECLARES a static data member of complete type int[12], i.e. expose the length of the array as part of the public API

    static const int scArr0[]; // DECLARES a static const data member of incomplete type `const int[]`, NO DEFINITION.
    static const int scArr1[]; // DECLARES a static const data member of incomplete type `const int[]`;
    static const int scArr2[18]; // DECLARES a static const data member of complete type `const int[18]`; i.e. expose the length of the array as part of the public API
};

int Foo::sx2; // definition

//int Foo::scx2; // err: `const` is part of the type
//const int Foo::scx2; // err: must provide initializer for definition of const
const int Foo::scx2; // definition; do not need initializer since the declaration has.
const int Foo::scx3 = 0; // definition


int Foo::sArr1[9]; // definition
// int Foo::sArr2[13]; // err. length must match
int Foo::sArr2[12]; // definition

//const int Foo::scArr1[12]; //error: uninitialized ‘const Foo::scArr1’ [-fpermissive]
const int Foo::scArr1[12]{99}; // definition

const int Foo::scArr2[18]{314159}; // definition

int main() {
    printf("%d\n", Foo().x); // okay
    //printf("%d\n", Foo::sx0); // poor linker can't find this symbol
    printf("%d\n", Foo::sx2);
    printf("%d\n", Foo::scx1);
    printf("%d\n", Foo::scx2);
    printf("%d\n", Foo::sArr1[0]);
    printf("sizeof(Foo::sArr1)=%lu\n", sizeof(Foo::sArr1)); // can sizeof() here though declared as an incomplete type, because the definition happens to appear in the same translation unit
    printf("%d\n", Foo::scArr1[0]);
    printf("%d\n", Foo::scArr2[0]);
    printf("%p\n", &Foo::scx2); // has addr
}