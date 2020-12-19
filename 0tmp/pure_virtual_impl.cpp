// cesun, 11/14/20 10:02 AM.

// being pure virtual means derived classes must override this method
// (as well as prohibit its class from being instantiated),
// this is orthogonal to having an implementation

#include <cstdio>

class Foo {
public:
    virtual void bar() = 0; // can't write its def in-place though

    virtual ~Foo() = default;
private:
    virtual void jojo() = 0;
};

void Foo::bar() {
    std::puts("impl of pure virtual!");
}

class FooD : public Foo {
public:
    void bar() override {
        std::puts("derived impl");
    }
};

#include <memory>
int main() {
    std::unique_ptr<Foo> up{new FooD{}};
    up->Foo::bar(); // "impl of pure virtual!"
}
