#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace mips {

// Returns machine code bytes (big-endian words).
std::vector<uint8_t> assemble(const std::string& source);

}  // namespace mips
