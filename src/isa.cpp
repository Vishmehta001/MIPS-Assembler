#include "../include/mips/isa.hpp"

mips::Decoded mips::decode(uint32_t w) {
    mips::Decoded d{};
    d.opcode = mips::get_opcode(w);

    if (d.opcode == 0) {
        d.type  = mips::InstrType::R;
        d.rs    = mips::get_rs(w);
        d.rt    = mips::get_rt(w);
        d.rd    = mips::get_rd(w);
        d.shamt = mips::get_shamt(w);
        d.funct = mips::get_funct(w);
    } else if (d.opcode == 2 || d.opcode == 3) {
        d.type = mips::InstrType::J;
        d.addr = mips::get_addr(w);
    } else {
        d.type = mips::InstrType::I;
        d.rs   = mips::get_rs(w);
        d.rt   = mips::get_rt(w);
        d.imm  = mips::get_imm(w);
    }
    return d;
}
