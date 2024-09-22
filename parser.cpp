#include "parser.hpp"
#include <stdexcept>
#include <iostream>

std::string tt2str(STokenType type) {
    switch (type) {
        case STokenType::UNKNOWN_X: return "<unknown_x>";
        case STokenType::UNKNOWN_Y: return "<unknown_y>";
        case STokenType::NUMBER: return "<number>";
        case STokenType::PLUS: return "<plus>";
        case STokenType::MINUS: return "<minus>";
        case STokenType::DIV: return "<div>";
        case STokenType::MUL: return "<mul>";
        case STokenType::EQU: return "<equ>";
        case STokenType::END: return "<end>";
        default: return "<unknown>";
    }
}

SParser::SParser(STokenStream &ts)
    : ts(ts) {}

SSystem SParser::parse() {
    SSystem system;

    parseEquation(system.a1, system.b1, system.c1);

    parseEquation(system.a2, system.b2, system.c2);

    return system;
}

std::int64_t SParser::parseCoefficient() {
    int sign = 1;
    if (ts.peek().type == STokenType::PLUS || ts.peek().type == STokenType::MINUS) {
        sign = (ts.next().type == STokenType::MINUS) ? -1 : 1;
    }

    SToken token = ts.next();
    if (token.type == STokenType::NUMBER) {
        return sign * std::atoll(token.value.value().c_str());
    } else {
        ts.pos--;
        return sign;
    }
}

std::int64_t SParser::parseConstant() {
    int sign = 1;
    SToken token = ts.next();
    if (token.type == STokenType::PLUS || token.type == STokenType::MINUS) {
        sign = (token.type == STokenType::MINUS) ? -1 : 1;
        token = ts.next();
    }

    if (token.type == STokenType::NUMBER) {
        return std::atoll(token.value.value().c_str()) * sign;
    } else {
        throw std::runtime_error("Systematic: Expected constant number");
    }
}

void SParser::parseEquation(std::int64_t &a, std::int64_t &b, std::int64_t &c) {
    std::optional<std::int64_t> coeff_x;
    std::optional<std::int64_t> coeff_y;

    for (int i = 0; i < 2; ++i) {
        std::int64_t coeff = parseCoefficient();

        SToken varToken = ts.next();
        if (varToken.type == STokenType::UNKNOWN_X) {
            if (coeff_x.has_value()) {
                throw std::runtime_error("Systematic: Duplicate x in equation");
            }
            coeff_x = coeff;
        } else if (varToken.type == STokenType::UNKNOWN_Y) {
            if (coeff_y.has_value()) {
                throw std::runtime_error("Systematic: Duplicate y in equation");
            }
            coeff_y = coeff;
        } else {
            throw std::runtime_error("Systematic: Unexpected token: expected x or y");
        }
    }

    expectTokenType(STokenType::EQU);
    c = parseConstant();

    a = coeff_x.value_or(0);
    b = coeff_y.value_or(0);
}

void SParser::expectTokenType(STokenType expected) {
    SToken token = ts.next();
    if (token.type != expected) {
        std::cerr << "Systematic: Expected " << tt2str(expected) << ", but got " << tt2str(token.type) << "\n";
        throw std::runtime_error("Systematic: Unexpected token type");
    }
}

void SParser::expectTokenTypes(STokenType a, STokenType b) {
    SToken token = ts.next();

    if (token.type == a || token.type == b)
        return;

    std::cerr << "Systematic: Expected " << tt2str(a) << " or " << tt2str(b) << " but got " << tt2str(token.type) << "\n";
    throw std::runtime_error("Systematic: Unexpected token type");
}
