#include "token_stream.hpp"
#include <stdexcept>

TokenStream::TokenStream(std::vector<Token> tokens)
    : tokens(tokens), pos(0) {}

Token TokenStream::next() {
    if (pos < tokens.size()) {
        return tokens[pos++];
    } else {
        throw std::runtime_error("Unexpected end of input");
    }
}

Token TokenStream::peek() {
    if (pos < tokens.size()) {
        return tokens[pos];
    } else {
        throw std::runtime_error("Unexpected end of input");
    }
}

bool TokenStream::hasNext() {
    return pos < tokens.size();
}

