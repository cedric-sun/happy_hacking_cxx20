// cesun, 11/29/20 1:30 AM.

#include <cstdio>

class Derived;

class Base {
public:
    virtual void operator-(const Base &r) {
        std::puts("virtual Base::operator-()");
    }
};

class Derived : public Base {
public:
    void operator-(const Base &r) override {
        std::puts("virtual Derived::operator-()");
    }

    virtual void operator-(const Derived &r) {
        std::puts("virtual derived - derived");
    }
};

void operator+(const Base &, const Base &) {
    std::puts("Base + Base");
}

void operator+(const Base &, const Derived &) {
    std::puts("Base + Derived");
}

void operator+(const Derived &, const Base &) {
    std::puts("Derived + Base");
}

void operator+(const Derived &, const Derived &) {
    std::puts("Derived + Derived");
}

int main() {
    Base *bp2d = new Derived;
    Base b;
    Derived d;
    *bp2d + d; // non-member op overload: static dispatch on all args
    *bp2d - d; //  `virtual Derived::operator-()`:
                // member virtual op reload dynamic dispatch on this
    *bp2d - *bp2d; // `virtual Derived::operator-()`
                    // but never multiple dynamic dispatch
    delete bp2d;
}
