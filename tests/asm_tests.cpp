#include "../include/mips/isa.hpp"


namespace mips {

Decoded decode(uint32_t w) {
    Decoded d{};
    d.opcode = get_opcode(w);
    if (d.opcode == 0) {
        d.type  = InstrType::R;
        d.rs    = get_rs(w);
        d.rt    = get_rt(w);
        d.rd    = get_rd(w);
        d.shamt = get_shamt(w);
        d.funct = get_funct(w);
    } else if (d.opcode == 2 || d.opcode == 3) {
        d.type = InstrType::J;
        d.addr = get_addr(w);
    } else {
        d.type = InstrType::I;
        d.rs   = get_rs(w);
        d.rt   = get_rt(w);
        d.imm  = get_imm(w);
    }
    return d;
}

} // namespace mips