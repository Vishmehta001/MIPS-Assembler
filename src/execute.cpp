
#include "mips/execute.hpp"
#include <iostream>
namespace mips {
void execute_example(Machine& m) {
    std::cout << "Executing example, PC=" << m.pc << "\n";
}
}
