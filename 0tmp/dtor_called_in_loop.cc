// cesun, 5/22/20 11:15 AM.

#include <iostream>

struct A {
    ~A() {
        std::cout << "A instance:" << this << " d'tor called " << std::endl;
    }
};

int main() {
    for (int i = 0; i < 5; ++i) {
        A a_obj;
    } // d'tor called at the end of each iteration
}