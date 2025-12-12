# 🧪 MIPS Assembler - Testing Guide

## Phase 1: Machine Class Tests

This guide will help you test the MIPS Assembler as we build it incrementally.

---

## ✅ Current Status (Phase 1)

### What's Implemented:
- ✅ Machine class with 32 registers, PC, HI, LO
- ✅ Memory operations (load32/store32)
- ✅ Register write protection ($zero is hardwired)
- ✅ Basic test suite

### What's NOT Yet Implemented:
- ❌ Instruction decoding
- ❌ Instruction execution  
- ❌ Assembly parser
- ❌ Binary I/O

---

## 🔧 How to Test

### Step 1: Clone the Repository
```bash
git clone https://github.com/Vishmehta001/MIPS-Assembler.git
cd MIPS-Assembler
```

### Step 2: Compile the Test
```bash
make -f Makefile.test
```

**Expected Output:**
```
=== Compiled successfully! ===
Run with: ./test_basic
```

### Step 3: Run the Test
```bash
./test_basic
```

**Expected Output (if everything works):**
```
=== MIPS Machine - Basic Test ===

[Test 1] Creating Machine with 1MB memory... OK
[Test 2] Checking registers initialized to 0... OK
[Test 3] Testing register writes... OK
[Test 4] Testing memory store32/load32... OK
[Test 5] Testing PC register... OK
[Test 6] Testing HI/LO registers... OK

=== All Tests PASSED! ===
Machine class is working correctly.
```

---

## 🐛 Troubleshooting

### Compilation Errors

**Error:** `fatal error: machine.hpp: No such file or directory`
**Solution:** Make sure you're in the project root directory.

**Error:** `g++: command not found`
**Solution:** Install g++ compiler:
```bash
# Ubuntu/Debian
sudo apt install g++

# macOS
xcode-select --install
```

### Test Failures

If any test fails, the program will output:
```
test_basic: tests/test_basic.cpp:XX: int main(): Assertion 'condition' failed.
Aborted (core dumped)
```

This means something is broken. **Report the exact line number and test that failed.**

---

## 📋 What to Report After Testing

Please tell me:

1. ✅ **Did it compile?** (Yes/No)
2. ✅ **Did all tests pass?** (Yes/No)
3. ❌ **If it failed, which test?** (Copy the error message)

**Example:**
```
Compiled: Yes
All tests passed: No
Failed at: [Test 4] - Assertion 'val == 0x12345678' failed
```

---

## 🔄 Clean Up

To remove the test binary:
```bash
make -f Makefile.test clean
```

---

## 📦 Next Phases

Once Phase 1 tests pass, we'll implement:
- **Phase 2:** Instruction decoding
- **Phase 3:** Basic instruction execution (add, lw, sw, etc.)
- **Phase 4:** Assembly parser
- **Phase 5:** Full ISA
- **Phase 6:** Debugger

Each phase will have its own test file that you can run to verify progress.

---

## 🎯 Quick Start Command

For fast testing:
```bash
make -f Makefile.test run
```

This compiles and runs the test in one command.
