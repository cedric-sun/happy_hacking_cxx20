// cesun, 5/21/20 2:06 PM.

#include <iostream>
#include <string>
#include <sstream>

#include "../util/type_name.h"

template<typename T>
void foo() {
    std::cout << type_name<T>() << std::endl;
}

template<typename T>
void bar(T x) {
    std::cout << type_name<T>() << std::endl;
}


int main() {
    foo<int>(); // requires explicit instantiation
    bar(42); // it's okay to omit explicit inst if type can be inferred.
}