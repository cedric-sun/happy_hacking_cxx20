// cesun, 5/21/20 3:03 PM.

#include <string>
#include <iostream>

int main() {
    int c;
    try {
        c = std::stoi("asdas123");
    } catch (std::invalid_argument &e) {
        std::cout << "invalid argument:" << e.what() << std::endl;
        exit(0);
    }
    std::cout << c << std::endl;
}
