// Basic test for Machine class - Phase 1
// Tests: Machine creation, memory operations, register operations

#include <iostream>
#include <cassert>
#include "../include/mips/machine.hpp"

using namespace std;
using namespace mips;

int main() {
    cout << "=== MIPS Machine - Basic Test ==="<< endl << endl;
    
    // Test 1: Create Machine with 1 MB memory
    cout << "[Test 1] Creating Machine with 1MB memory...";
    Machine m(1024 * 1024);  // 1 MB
    cout << " OK" << endl;
    
    // Test 2: Check registers are initialized to 0
    cout << "[Test 2] Checking registers initialized to 0...";
    for (int i = 0; i < 32; i++) {
        assert(m.r[i] == 0);
    }
    assert(m.pc == 0);
    assert(m.hi == 0);
    assert(m.lo == 0);
    cout << " OK" << endl;
    
    // Test 3: Write to registers (except $zero)
    cout << "[Test 3] Testing register writes...";
    m.write_reg(0, 999);  // Should stay 0 (hardwired)
    assert(m.r[0] == 0);
    
    m.write_reg(1, 100);  // $at = 100
    assert(m.r[1] == 100);
    
    m.write_reg(8, 0xDEADBEEF);  // $t0 = 0xDEADBEEF
    assert(m.r[8] == 0xDEADBEEF);
    cout << " OK" << endl;
    
    // Test 4: Memory store and load
    cout << "[Test 4] Testing memory store32/load32...";
    m.store32(0x1000, 0x12345678);
    uint32_t val = m.load32(0x1000);
    assert(val == 0x12345678);
    cout << " OK" << endl;
    
    // Test 5: PC register
    cout << "[Test 5] Testing PC register...";
    m.pc = 0x400000;
    assert(m.pc == 0x400000);
    cout << " OK" << endl;
    
    // Test 6: HI/LO registers
    cout << "[Test 6] Testing HI/LO registers...";
    m.hi = 0xAAAAAAAA;
    m.lo = 0xBBBBBBBB;
    assert(m.hi == 0xAAAAAAAA);
    assert(m.lo == 0xBBBBBBBB);
    cout << " OK" << endl;
    
    cout << endl << "=== All Tests PASSED! ===" << endl;
    cout << "Machine class is working correctly." << endl;
    
    return 0;
}
