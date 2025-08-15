
#include "mips/machine.hpp"
#include "mips/execute.hpp"
#include <iostream>
int main() {
    mips::Machine m;
    mips::execute_example(m);
    std::cout << "Starter OK" << std::endl;
    return 0;
}
