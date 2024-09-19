#include <iostream>
#include <vector>
#include <optional>
#include <string>

#include "token.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "token_stream.hpp"
#include "matrix.hpp"

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

    std::string input(s1);
    input.push_back('\n');
    input.append(s2);

    Lexer lexer(input);
    std::vector<Token> tokens = lexer.lex();
    TokenStream ts(tokens);
    Parser parser(ts);

    try {
        System system = parser.parse();
        Mat2x2 mat(system.a1, system.a2, system.b1, system.b2);
        Mat2x2 mat_x(system.c1, system.c2, system.b1, system.b2);
        Mat2x2 mat_y(system.a1, system.a2, system.c1, system.c2);

        std::int64_t determinant = mat.calculateDeterminant();
        std::int64_t determinant_x = mat_x.calculateDeterminant();
        std::int64_t determinant_y = mat_y.calculateDeterminant();

        if (determinant == 0) {
            if (determinant_x == 0 &&
                determinant_y == 0) {
                std::cout << "The system has inifnite solutions (find the type yourself)" << std::endl;
            } else {
                std::cerr << "The system has no solutions" << std::endl;
            }
            return 0;
        }

        double x = (double) determinant_x / determinant;
        double y = (double) determinant_y / determinant;

        std::cout << "The system has one solution (" << x << ", " << y << ")" << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << "error parsing: " << e.what() << std::endl;
    }

    return 0;
}
