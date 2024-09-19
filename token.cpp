#include "token.hpp"

Token::Token(TokenType type)
    : type(type) {

}

Token::Token(TokenType type, std::optional<std::string> value)
    : type(type), value(value) {

}
