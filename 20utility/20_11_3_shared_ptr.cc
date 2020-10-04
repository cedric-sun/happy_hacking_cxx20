// cesun, 10/4/20 2:43 PM.

#include <memory>

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

int main() {
    auto a = std::make_shared<A>(42);
    auto b = a;
    auto c = b;
    printf("use_count: %d\n", a.use_count());
    a.reset();
    printf("use_count: %d\n", a.use_count()); // return 0 if a has no managed object
    printf("use_count: %d\n", b.use_count());
    b.reset();
    printf("use_count: %d\n", c.use_count());
    c.reset();
    printf("Program exit\n");
}
