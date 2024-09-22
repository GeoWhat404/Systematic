#include "token.hpp"

SToken::SToken(STokenType type)
    : type(type) {

}

SToken::SToken(STokenType type, std::optional<std::string> value)
    : type(type), value(value) {

}
