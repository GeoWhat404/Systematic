#include "parser.hpp"
#include <stdexcept>
#include <iostream>

std::string tt2str(TokenType type) {
    switch (type) {
        case TokenType::UNKNOWN_X: return "<unknown_x>";
        case TokenType::UNKNOWN_Y: return "<unknown_y>";
        case TokenType::NUMBER: return "<number>";
        case TokenType::PLUS: return "<plus>";
        case TokenType::MINUS: return "<minus>";
        case TokenType::DIV: return "<div>";
        case TokenType::MUL: return "<mul>";
        case TokenType::EQU: return "<equ>";
        case TokenType::END: return "<end>";
        default: return "<unknown>";
    }
}

Parser::Parser(TokenStream &ts)
    : ts(ts) {}

System Parser::parse() {
    System system;

    parseEquation(system.a1, system.b1, system.c1);

    parseEquation(system.a2, system.b2, system.c2);

    return system;
}

std::int64_t Parser::parseCoefficient() {
    int sign = 1;
    if (ts.peek().type == TokenType::PLUS || ts.peek().type == TokenType::MINUS) {
        sign = (ts.next().type == TokenType::MINUS) ? -1 : 1;
    }

    Token token = ts.next();
    if (token.type == TokenType::NUMBER) {
        return sign * std::atoll(token.value.value().c_str());
    } else {
        ts.pos--;
        return sign;
    }
}

std::int64_t Parser::parseConstant() {
    int sign = 1;
    Token token = ts.next();
    if (token.type == TokenType::PLUS || token.type == TokenType::MINUS) {
        sign = (token.type == TokenType::MINUS) ? -1 : 1;
        token = ts.next();
    }

    if (token.type == TokenType::NUMBER) {
        return std::atoll(token.value.value().c_str()) * sign;
    } else {
        throw std::runtime_error("Expected constant number");
    }
}

void Parser::parseEquation(std::int64_t &a, std::int64_t &b, std::int64_t &c) {
    std::optional<std::int64_t> coeff_x;
    std::optional<std::int64_t> coeff_y;

    for (int i = 0; i < 2; ++i) {
        std::int64_t coeff = parseCoefficient();

        Token varToken = ts.next();
        if (varToken.type == TokenType::UNKNOWN_X) {
            if (coeff_x.has_value()) {
                throw std::runtime_error("Duplicate x in equation");
            }
            coeff_x = coeff;
        } else if (varToken.type == TokenType::UNKNOWN_Y) {
            if (coeff_y.has_value()) {
                throw std::runtime_error("Duplicate y in equation");
            }
            coeff_y = coeff;
        } else {
            throw std::runtime_error("Unexpected token: expected x or y");
        }
    }

    expectTokenType(TokenType::EQU);
    c = parseConstant();

    a = coeff_x.value_or(0);
    b = coeff_y.value_or(0);
}

void Parser::expectTokenType(TokenType expected) {
    Token token = ts.next();
    if (token.type != expected) {
        std::cerr << "Expected " << tt2str(expected) << ", but got " << tt2str(token.type) << "\n";
        throw std::runtime_error("Unexpected token type");
    }
}

void Parser::expectTokenTypes(TokenType a, TokenType b) {
    Token token = ts.next();

    if (token.type == a || token.type == b)
        return;

    std::cerr << "Expected " << tt2str(a) << " or " << tt2str(b) << " but got " << tt2str(token.type) << "\n";
    throw std::runtime_error("Unexpected token type");
}
