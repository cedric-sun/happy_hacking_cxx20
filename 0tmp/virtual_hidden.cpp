// cesun, 11/14/20 8:17 AM.

class Base {
public:
    virtual void m0() = 0;

    virtual void m0(int a) {

    }
};

class Derived : public Base {
public:
    using Base::m0;

    void m0() override {

    }
};

int main() {

}
