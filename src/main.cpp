#include "../include/mips/cpu.hpp"
#include "../include/mips/assembler.hpp"
#include "mips/isa.hpp"
#include <fstream>
#include <iostream>
#include <iterator>


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: mips-exec <input.s>\n";
        return 1;
    }
    std::ifstream fs(argv[1]);
    if (!fs) {
        std::cerr << "Failed to open " << argv[1] << "\n";
        return 1;
    }

    std::string src((std::istreambuf_iterator<char>(fs)),
                     std::istreambuf_iterator<char>());
    mips::Decoded d = mips::decode(0x012A4020); // example: add $t0, $t1, $t2
    std::cout << "Decoded example instruction: opcode=" << unsigned(d.opcode)
              << " rs=" << unsigned(d.rs)
              << " rt=" << unsigned(d.rt)
              << " rd=" << unsigned(d.rd)
              << " shamt=" << unsigned(d.shamt)
              << " funct=" << unsigned(d.funct) << "\n";

}
