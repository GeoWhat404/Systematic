#include "token_stream.hpp"
#include <stdexcept>

STokenStream::STokenStream(std::vector<SToken> tokens)
    : tokens(tokens), pos(0) {}

SToken STokenStream::next() {
    if (pos < tokens.size()) {
        return tokens[pos++];
    } else {
        throw std::runtime_error("Unexpected end of input");
    }
}

SToken STokenStream::peek() {
    if (pos < tokens.size()) {
        return tokens[pos];
    } else {
        throw std::runtime_error("Unexpected end of input");
    }
}

bool STokenStream::hasNext() {
    return pos < tokens.size();
}

