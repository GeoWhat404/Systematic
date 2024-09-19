#include "matrix.hpp"

Mat2x2::Mat2x2(std::int64_t a1, std::int64_t a2,
               std::int64_t b1, std::int64_t b2)
    : a1(a1), a2(a2), b1(b1), b2(b2) {

}

std::int64_t Mat2x2::calculateDeterminant() {
    return a1 * b2 - a2 * b1;
}
