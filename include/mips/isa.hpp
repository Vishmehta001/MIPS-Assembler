#pragma once
#include <cstdint>

namespace mips {

enum class InstrType { R, I, J };

struct Decoded {
    InstrType type;
    uint8_t  opcode{0}, rs{0}, rt{0}, rd{0}, shamt{0}, funct{0};
    int16_t  imm{0};
    uint32_t addr{0};
};

inline uint8_t  get_opcode(uint32_t w) { return (w >> 26) & 0x3F; }
inline uint8_t  get_rs(uint32_t w)     { return (w >> 21) & 0x1F; }
inline uint8_t  get_rt(uint32_t w)     { return (w >> 16) & 0x1F; }
inline uint8_t  get_rd(uint32_t w)     { return (w >> 11) & 0x1F; }
inline uint8_t  get_shamt(uint32_t w)  { return (w >> 6)  & 0x1F; }
inline uint8_t  get_funct(uint32_t w)  { return  w        & 0x3F; }
inline int16_t  get_imm(uint32_t w)    { return static_cast<int16_t>(w & 0xFFFF); }
inline uint32_t get_addr(uint32_t w)   { return w & 0x03FFFFFFu; }

// Declaration (still inside the namespace)
Decoded decode(uint32_t w);

} // namespace mips
