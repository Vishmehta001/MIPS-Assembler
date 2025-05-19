<<<<<<< HEAD
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
=======
cmake_minimum_required(VERSION 3.21)
project(Project)
set(CMAKE_CXX_STANDARD 23)
find_package(Catch2 REQUIRED)
find_package(GTest REQUIRED)
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
add_library(my_library lib.cpp)
add_executable(my_cli_tool cli.cpp)
add_executable(my_gui_tool gui.cpp)
add_executable(my_catch2_tests tests.cpp)
add_executable(my_gtest_tests tests2.cpp)
target_link_libraries(my_cli_tool my_library)
target_link_libraries(my_gui_tool my_library Qt6::Core Qt6::Widgets)
target_link_libraries(my_catch2_tests my_library Catch2::Catch2WithMain)
target_link_libraries(my_gtest_tests my_library GTest::gtest_main)
>>>>>>> 159d286 (Set up template for exercise)
