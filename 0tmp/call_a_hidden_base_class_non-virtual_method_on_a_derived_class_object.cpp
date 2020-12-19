// cesun, 11/29/20 12:11 AM.

#include <cstdio>

class Base {
protected:
    int value;
public:
    Base(int value) : value(value) {}

    void foo() {
        std::printf("Base non-virtual foo: %d\n", value);
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base{value} {}

    void foo() {
        std::printf("Derived non-virtual foo: %d\n", value);
    }
};

int main() {
    Derived dobj{42};
    dobj.foo();
    dobj.Base::foo();
}
