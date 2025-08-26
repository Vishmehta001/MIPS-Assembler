
#pragma once
#include <array>
#include <cstdint>
#include <vector>

namespace mips {
struct Machine {
    std::array<uint32_t, 32> regs{};
    uint32_t pc = 0;
    std::vector<uint8_t> mem;
    explicit Machine(size_t mem_size_bytes = 1<<20);
};
}
