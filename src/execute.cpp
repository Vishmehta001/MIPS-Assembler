
#include "../include/mips/machine.hpp"


#include <iostream>
namespace mips {
void execute_example(Machine& m) {
    std::cout << "Executing example, PC=" << m.pc << "\n";
}
}
