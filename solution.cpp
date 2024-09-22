#include "solution.hpp"

SSolution::SSolution(std::int64_t x, std::int64_t y) : x(x), y(y) { }
SSolution::SSolution(std::string msg) : msg(msg) { }
SSolution::SSolution(std::int64_t x, std::int64_t y, std::string msg) : x(x), y(y), msg(msg) { }
SSolution::SSolution() { }
