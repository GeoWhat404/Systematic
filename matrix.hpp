#pragma once

#include <cstdint>

class SMat2x2 {
    public:
        SMat2x2(std::int64_t a1, std::int64_t a2,
               std::int64_t b1, std::int64_t b2);
        std::int64_t calculateDeterminant();

        std::int64_t a1;
        std::int64_t a2;
        std::int64_t b1;
        std::int64_t b2;
};
