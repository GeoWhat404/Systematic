#pragma once

#include <cstdint>

class Mat2x2 {
    public:
        Mat2x2(std::int64_t a1, std::int64_t a2,
               std::int64_t b1, std::int64_t b2);
        std::int64_t calculateDeterminant();

        std::int64_t a1;
        std::int64_t a2;
        std::int64_t b1;
        std::int64_t b2;
};
