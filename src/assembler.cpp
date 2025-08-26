#include "../include/mips/assembler.hpp"
#include "../include/mips/isa.hpp"
#include <sstream>
#include <algorithm>

namespace mips {

// Minimal stub: supports lines like ".word 0xXXXXXXXX" (hex) so we can test pipeline.
static inline uint32_t parse_word_hex(const std::string& tok) {
    uint32_t val = 0;
    std::stringstream ss;
    ss << std::hex << tok;
    ss >> val;
    return val;
}

std::vector<uint8_t> assemble(const std::string& source) {
    std::vector<uint8_t> out;
    std::istringstream in(source);
    std::string line;

    while (std::getline(in, line)) {
        // strip comments after '#'
        if (auto pos = line.find('#'); pos != std::string::npos) line.resize(pos);
        // trim
        line.erase(line.begin(),
                   std::find_if(line.begin(), line.end(), [](unsigned char c){return !std::isspace(c);} ));
        line.erase(std::find_if(line.rbegin(), line.rend(),
                   [](unsigned char c){return !std::isspace(c);} ).base(), line.end());
        if (line.empty()) continue;

        if (line.rfind(".word", 0) == 0) {
            std::istringstream ls(line);
            std::string dotword, value;
            ls >> dotword >> value; // ".word 0xDEADBEEF"
            uint32_t w = parse_word_hex(value);
            // big-endian output
            out.push_back((w >> 24) & 0xFF);
            out.push_back((w >> 16) & 0xFF);
            out.push_back((w >> 8) & 0xFF);
            out.push_back(w & 0xFF);
            continue;
        }

        // TODO: Next steps: parse real instructions using mips-instructions.csv
        // For now, ignore unknown lines.
    }

    return out;
}

} // namespace mips
