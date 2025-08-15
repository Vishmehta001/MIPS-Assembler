
cmake_minimum_required(VERSION 3.20)
project(mips CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pedantic -O2)

add_library(mips_core
    src/machine.cpp src/decode.cpp src/execute.cpp
)
target_include_directories(mips_core PUBLIC include)

add_executable(mips-execute tools/mips-execute.cpp)
target_link_libraries(mips-execute PRIVATE mips_core)
