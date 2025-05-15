cmake_minimum_required(VERSION 3.15)
project(JITCompiler)

set(CMAKE_CXX_STANDARD 17)

# Add subdirectories
add_subdirectory(src)

# LLVM and AsmJit Setup
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# AsmJit
include_directories(${CMAKE_SOURCE_DIR}/third_party/asmjit/src)
