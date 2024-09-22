#pragma once

#include <string>
#include <optional>

class SSolution {
    public:
        std::optional<std::string> msg;
        std::optional<std::int64_t> x;
        std::optional<std::int64_t> y;

        SSolution(std::int64_t x, std::int64_t y);
        SSolution(std::string msg);
        SSolution(std::int64_t x, std::int64_t y, std::string msg);
        SSolution();
};
