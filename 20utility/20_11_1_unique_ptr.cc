// cesun, 10/4/20 2:22 PM.

#include <cstdio>

struct A {
public:
    A(const int id) : id_{id} {
        printf("#%d Instance of A created at %p\n", id, this);
    }

    ~A() {
        printf("#%d Instance of A destroyed at %p\n", id_, this);
    }

    const int id_;
};

#include <memory>

void foo() {
    auto u2 = std::make_unique<A>(31415);
}

// how to "pass unique_ptr around":
void bar(A &aref) {
    printf("Inspecting #%d A instance at %p\n", aref.id_, &aref);
}

int main() {
    auto u = std::make_unique<A>(42);
    foo();
}
