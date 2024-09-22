#pragma once

#include <iostream>

#include "system.hpp"
#include "solution.hpp"
#include "matrix.hpp"

class Systematic {
    public:
        Systematic(SSystem system);
        Systematic(std::string equ1, std::string equ2);

        SSolution solveSystem();

    private:
        SSystem system;
};
