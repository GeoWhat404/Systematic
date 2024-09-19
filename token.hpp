#pragma once

#include <optional>
#include <string>

enum class TokenType {
    UNKNOWN_X,
    UNKNOWN_Y,
    NUMBER,
    PLUS,
    MINUS,
    DIV,
    MUL,
    EQU,
    END,
};

class Token {
    public:
        TokenType type;
        std::optional<std::string> value;

        Token(TokenType type);
        Token(TokenType type, std::optional<std::string> value);
};
