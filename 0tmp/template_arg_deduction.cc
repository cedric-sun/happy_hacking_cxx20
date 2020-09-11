// cesun, 9/3/20 5:55 PM.

#include "../util/type_name.h"
#include <iostream>


template<typename T>
void foo(T &&t) {
    std::cout << type_name<decltype(t)>() << std::endl;
}

template<typename F>
void bar(F func) {
    std::cout << type_name<F>() << std::endl;
    std::cout << sizeof(F) << std::endl;
}

int main() {
    int a = 42;
    foo(a);
    bar([a](int x) { return x + a + 42; });
}