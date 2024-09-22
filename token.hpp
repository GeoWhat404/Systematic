#pragma once

#include <optional>
#include <string>

enum class STokenType {
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

class SToken {
    public:
        STokenType type;
        std::optional<std::string> value;

        SToken(STokenType type);
        SToken(STokenType type, std::optional<std::string> value);
};
