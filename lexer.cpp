#include "lexer.hpp"
#include <iostream>

SLexer::SLexer(std::string src)
    :src(src) {

}

std::vector<SToken> SLexer::lex() {
    std::vector<SToken> tokens;
    for (int i = 0; i < src.length(); i++) {
        current_pos = i;

        switch (src.at(i)) {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                break;

            case '+': tokens.push_back(SToken(STokenType::PLUS));     break;
            case '-': tokens.push_back(SToken(STokenType::MINUS));    break;
            case '/': tokens.push_back(SToken(STokenType::DIV));      break;
            case '*': tokens.push_back(SToken(STokenType::MUL));      break;
            case '=': tokens.push_back(SToken(STokenType::EQU));      break;

            case 'x':
            case 'X':
                tokens.push_back(SToken(STokenType::UNKNOWN_X));
                break;
            case 'y':
            case 'Y':
                tokens.push_back(SToken(STokenType::UNKNOWN_Y));
                break;

            default:
                std::string num;
                if (std::isdigit(src.at(i))) {
                    while (i < src.length() && std::isdigit(src.at(i))) {
                        num.push_back(src.at(i));
                        i++;
                    }
                    tokens.push_back(SToken(STokenType::NUMBER, num));
                    i--;
                } else {
                    std::cerr << "Unexpected character: " << src.at(i) << std::endl;
                }
                break;
        }
    }
    tokens.push_back(SToken(STokenType::END));
    return tokens;
}

