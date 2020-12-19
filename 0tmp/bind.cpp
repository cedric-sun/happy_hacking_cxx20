// cesun, 11/15/20 11:50 AM.

#include <functional>
#include <cstdio>

void foo(int a, double b) {
    std::printf("%d, %f\n", a, b);
}

class Bar {
public:
    void bazz(int a) {
        std::printf("bazz: %d\n", a);
    }
};

int main() {
    auto bound_foo = std::bind(foo, 42, std::placeholders::_1);
    bound_foo(99.0);
    Bar barobj;
    // TODO: second arg of bind be `barobj` or `&barobj` or `std::ref(barobj)`?
    auto bound_bazz = std::bind(&Bar::bazz, &barobj, std::placeholders::_1);
    bound_bazz(1);
    auto bound_bazz2 = std::bind(&Bar::bazz, std::placeholders::_1, 42);
}
