// cesun, 5/22/20 12:02 PM.

#include <iostream>

void foo(int &ref) {
    std::cout << ref << std::endl;
}

int main() {
    int *p = nullptr;
    foo(*p);
}