#pragma once
#include <cstdint>
#include <vector>
#include <array>
#include <stdexcept>

namespace mips {

struct CPU {
    std::array<uint32_t, 32> r{};  // GPRs ($0..$31). r[0] must remain 0.
    uint32_t hi{0}, lo{0};
    uint32_t pc{0};

    std::vector<uint8_t> mem;

    explicit CPU(size_t mem_size = (1u << 20))  // 1 MiB default
        : mem(mem_size, 0) {}

    uint32_t load32(uint32_t addr) const;
    void store32(uint32_t addr, uint32_t value);

    // Utility: keep $zero hardwired to 0 when writing.
    void write_reg(uint8_t idx, uint32_t val) {
        if (idx != 0) r[idx] = val;
    }
};

}  // namespace mips
