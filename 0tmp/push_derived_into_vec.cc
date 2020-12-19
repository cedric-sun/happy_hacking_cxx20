// cesun, 10/17/20 7:55 PM.

struct A {
    int avalue = 3;
};

struct B : public A {
    int bvalue = 5;
};

#include <vector>
#include <cstdio>

int main() {
    std::vector<A *> avec;
    B binst;
    binst.bvalue = 444;
    avec.push_back(&binst);
    printf("%d %d\n", avec.front()->avalue, reinterpret_cast<B*>(avec.front())->bvalue);
}

