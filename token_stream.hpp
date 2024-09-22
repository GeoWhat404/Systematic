#pragma once

#include "token.hpp"
#include <vector>

class STokenStream {
public:
    STokenStream(std::vector<SToken> tokens);

    SToken next();
    SToken peek();
    bool hasNext();

    size_t pos;

private:
    std::vector<SToken> tokens;
};

