#include "lexer.hpp"
#include <iostream>

Lexer::Lexer(std::string src)
    :src(src) {

}

std::vector<Token> Lexer::lex() {
    std::vector<Token> tokens;
    for (int i = 0; i < src.length(); i++) {
        current_pos = i;

        switch (src.at(i)) {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                break;

            case '+': tokens.push_back(Token(TokenType::PLUS));     break;
            case '-': tokens.push_back(Token(TokenType::MINUS));    break;
            case '/': tokens.push_back(Token(TokenType::DIV));      break;
            case '*': tokens.push_back(Token(TokenType::MUL));      break;
            case '=': tokens.push_back(Token(TokenType::EQU));      break;

            case 'x':
            case 'X':
                tokens.push_back(Token(TokenType::UNKNOWN_X));
                break;
            case 'y':
            case 'Y':
                tokens.push_back(Token(TokenType::UNKNOWN_Y));
                break;

            default:
                std::string num;
                if (std::isdigit(src.at(i))) {
                    while (i < src.length() && std::isdigit(src.at(i))) {
                        num.push_back(src.at(i));
                        i++;
                    }
                    tokens.push_back(Token(TokenType::NUMBER, num));
                    i--;
                } else {
                    std::cerr << "Unexpected character: " << src.at(i) << std::endl;
                }
                break;
        }
    }
    tokens.push_back(Token(TokenType::END));
    return tokens;
}

