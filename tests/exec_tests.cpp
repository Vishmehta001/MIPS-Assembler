#include "../include/mips/cpu.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace mips;
    CPU cpu(1024);
    // store/load round-trip
    cpu.store32(0, 0xDEADBEEF);
    uint32_t x = cpu.load32(0);
    assert(x == 0xDEADBEEF);

    // $zero must remain 0
    cpu.write_reg(0, 123);
    assert(cpu.r[0] == 0);

    return 0;
}
