#include <iostream>
#include <optional>
#include <string>

#include "systematic.hpp"

int main(int argc, char **argv) {
    std::string s1;
    std::string s2;

    std::cout << "Enter equation 1: ";
    std::getline(std::cin, s1);

    std::cout << "Enter equation 2: ";
    std::getline(std::cin, s2);

    if (s1.empty() || s2.empty()) {
        std::cerr << "Invalid system entries" << std::endl;
        return 1;
    }

    Systematic sys(s1, s2);
    SSolution solution = sys.solveSystem();

    std::cout << solution.msg->c_str() << std::endl;

    return 0;
}
