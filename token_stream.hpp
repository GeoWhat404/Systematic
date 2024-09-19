#pragma once

#include "token.hpp"
#include <vector>

class TokenStream {
public:
    TokenStream(std::vector<Token> tokens);

    Token next();
    Token peek();
    bool hasNext();

    size_t pos;

private:
    std::vector<Token> tokens;
};

