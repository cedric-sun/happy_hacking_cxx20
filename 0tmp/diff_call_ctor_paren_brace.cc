// cesun, 5/21/20 2:44 PM.

#include <vector>
#include <iostream>
#include <iomanip>

int main() {
    std::vector<int> a(10);
    std::vector<int> b{10};
    for (int e : a) {
        std::cout << std::setw(4) << e;
    }
    std::cout << std::endl;
    for (int e : b) {
        std::cout << std::setw(4) << e;
    }
    std::cout << std::endl;
}