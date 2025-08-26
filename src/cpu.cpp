#include "../include/mips/cpu.hpp"

namespace mips {

static inline void check_align(uint32_t addr, uint32_t align) {
    if (addr % align) throw std::runtime_error("Unaligned access");
}

uint32_t CPU::load32(uint32_t addr) const {
    check_align(addr, 4);
    if (addr + 3 >= mem.size()) throw std::runtime_error("Out of bounds load");
    // MIPS commonly uses big-endian in classic specs; choose one and be consistent.
    // We'll use big-endian encoding of words in memory here:
    uint32_t b0 = mem[addr];
    uint32_t b1 = mem[addr + 1];
    uint32_t b2 = mem[addr + 2];
    uint32_t b3 = mem[addr + 3];
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3);
}

void CPU::store32(uint32_t addr, uint32_t value) {
    check_align(addr, 4);
    if (addr + 3 >= mem.size()) throw std::runtime_error("Out of bounds store");
    mem[addr]     = static_cast<uint8_t>(value >> 24);
    mem[addr + 1] = static_cast<uint8_t>(value >> 16);
    mem[addr + 2] = static_cast<uint8_t>(value >> 8);
    mem[addr + 3] = static_cast<uint8_t>(value);
}

}  // namespace mips
