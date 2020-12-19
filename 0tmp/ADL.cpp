// cesun, 11/29/20 1:32 AM.
#include <cstdio>

class A {};
class B {};

void operator+(const A &,const A &) { std::puts("A+A"); }
void operator+(const A &,const B &) { std::puts("A+B"); }
void operator+(const B &,const A &) { std::puts("B+A"); }
void operator+(const B &,const B &) { std::puts("B+B"); }

int main() {
    A a;
    B b;
    a+a;
    a+b;
    b+a;
    b+b;
}
