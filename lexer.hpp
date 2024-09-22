#pragma once

#include <vector>
#include <string>
#include "token.hpp"

class SLexer {
    public:
        SLexer(std::string src);
        std::vector<SToken> lex();

    private:
        std::string src;
        int current_pos;
};
