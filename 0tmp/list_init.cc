// cesun, 9/2/20 1:32 PM.
#include <cstdio>
#include <initializer_list>

struct Foo {
    Foo(int);

    Foo(std::initializer_list<int>);

    int x;
    int xArr[32];

    void print();
};

Foo::Foo(int x) {
    this->x = x;
}

Foo::Foo(std::initializer_list<int> l) {
    int i = 0;
    for (int e : l) {
        xArr[i++] = e;
    }
}

void Foo::print() {
    printf("x:%d\n", x);
    printf("xArr:");
    for(int e : xArr) {
        printf(" %d", e);
    }
    putchar('\n');
}

int main() {
    Foo fooInst{1,2,3,42};
    fooInst.print();
}