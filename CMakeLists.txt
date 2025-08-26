cmake_minimum_required(VERSION 3.20)
project(mips LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(mips STATIC
    src/cpu.cpp
    src/isa.cpp
    src/assembler.cpp
)
target_include_directories(mips PUBLIC include)

add_executable(mips-exec src/main.cpp)
target_link_libraries(mips-exec PRIVATE mips)

# Minimal tests without external framework (assert-based).
enable_testing()
add_executable(mips-tests
    tests/asm_tests.cpp
    tests/exec_tests.cpp
)
target_link_libraries(mips-tests PRIVATE mips)
add_test(NAME mips-tests COMMAND mips-tests)
