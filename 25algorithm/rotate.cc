// cesun, 5/21/20 5:50 PM.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<int> vec{1, 2, 4, 4, 4, 4, 4, 3, 5};
    int i = 7;
    auto it = std::upper_bound(vec.begin(), vec.begin() + i, vec[i]);
    std::cout << "it pos: "<< it - vec.cbegin() << std::endl;
    std::cout <<"begin: "<<vec.rend() - i - 1 - vec.crend() <<
    "mid: "<< vec.rend()-i-vec.crend()<<
    "end: "<<  (++std::make_reverse_iterator(it)) - vec.crend()<<std::endl;
    std::rotate(vec.rend() - i - 1, vec.rend() - i, std::make_reverse_iterator(it));
    for (auto i : vec)
        std::cout << std::setw(4) << i;
    std::cout << std::endl;
}