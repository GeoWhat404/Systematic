#pragma once

#include <vector>
#include <string>
#include "token.hpp"

class Lexer {
    public:
        Lexer(std::string src);
        std::vector<Token> lex();

    private:
        std::string src;
        int current_pos;
};
