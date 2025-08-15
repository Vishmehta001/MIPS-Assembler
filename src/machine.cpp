
#include "mips/machine.hpp"
namespace mips {
Machine::Machine(size_t mem_size_bytes) : mem(mem_size_bytes, 0) {}
}
