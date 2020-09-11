// cesun, 5/22/20 6:51 AM.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> a{1, 2, 3, 4, 5};
    auto it = std::lower_bound(a.begin(), a.end(), 3);
    std::cout << it - a.cbegin() << std::endl;
}

