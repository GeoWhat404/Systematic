#pragma once

#include "system.hpp"
#include "token_stream.hpp"

class SParser {
public:
    SParser(STokenStream &ts);
    SSystem parse();

private:
    STokenStream &ts;

    std::int64_t parseCoefficient();
    std::int64_t parseConstant();
    void parseEquation(std::int64_t &a, std::int64_t &b, std::int64_t &c);
    void expectTokenType(STokenType expected);
    void expectTokenTypes(STokenType a, STokenType b);
};
