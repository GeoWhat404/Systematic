#include <sstream>

#include "systematic.hpp"
#include "matrix.hpp"

#include "lexer.hpp"
#include "parser.hpp"

Systematic::Systematic(SSystem system) : system(system) { }

Systematic::Systematic(std::string equ1, std::string equ2) {
    SLexer lexer(equ1.append("\n").append(equ2));
    STokenStream ts(lexer.lex());
    SParser parser(ts);

    try {
        system = parser.parse();

    } catch (std::runtime_error) {
        throw std::runtime_error("Systematic: Error parsing");
    }
}

SSolution Systematic::solveSystem() {
        SSolution solution;
        SMat2x2 mat(system.a1, system.a2, system.b1, system.b2);
        SMat2x2 mat_x(system.c1, system.c2, system.b1, system.b2);
        SMat2x2 mat_y(system.a1, system.a2, system.c1, system.c2);

        std::int64_t determinant = mat.calculateDeterminant();
        std::int64_t determinant_x = mat_x.calculateDeterminant();
        std::int64_t determinant_y = mat_y.calculateDeterminant();

        if (determinant == 0) {
            if (determinant_x == 0 &&
                determinant_y == 0) {
                solution.msg = "The system has inifnite solutions (find the type yourself) because D = Dx = Dy = 0";
            } else {
                solution.msg = "The system has no solutions because D = 0 and Dx != 0 and/or Dy != 0";
            }
            return solution;
        }

        double x = (double) determinant_x / determinant;
        double y = (double) determinant_y / determinant;

        solution.x = x;
        solution.y = y;

        std::stringstream ss;
        ss << "The system has one solution (" << x << ", " << y << ")";
        solution.msg = ss.str();

        return solution;
}
