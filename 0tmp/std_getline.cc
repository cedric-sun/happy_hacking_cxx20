// cesun, 5/21/20 2:55 PM.

#include <string>
#include <iostream>
#include <iomanip>

int main() {
    for (std::string linestr; std::getline(std::cin, linestr);) {
        // DOES NOT include newline
        for (char c : linestr) {
            std::cout << "0x" << std::setw(3) << std::left << std::hex << static_cast<int>(c);
        }
        std::cout << std::endl;
    }
    std::cout << "Bye." << std::endl;
}
