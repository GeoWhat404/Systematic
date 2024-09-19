#pragma once

#include "system.hpp"
#include "token_stream.hpp"

class Parser {
public:
    Parser(TokenStream &ts);
    System parse();

private:
    TokenStream &ts;

    std::int64_t parseCoefficient();
    std::int64_t parseConstant();
    void parseEquation(std::int64_t &a, std::int64_t &b, std::int64_t &c);
    void expectTokenType(TokenType expected);
    void expectTokenTypes(TokenType a, TokenType b);
};
