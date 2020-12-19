// cesun, 10/2/20 7:51 PM.

template<typename T>
T foo() {
    T x{32};
    return x;
}

#include "../util/type_name.h"
#include <iostream>
using namespace std;
int main() {
    cout<< type_name<decltype(&foo<int>)>()<<endl;
}

