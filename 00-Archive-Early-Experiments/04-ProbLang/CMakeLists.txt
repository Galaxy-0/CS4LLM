cmake_minimum_required(VERSION 3.10)

# 项目代号：ProbLang
project(ProbLang VERSION 0.1.0 LANGUAGES CXX C)

# 我们要用大厂最高规格的标准来写：强制开启所有极其苛刻的代码审查警告
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O0 -g")

# 指定头文件目录 (Include Directories)
include_directories(${CMAKE_SOURCE_DIR}/include)

# 搜集我们未来写的所有的编译器源码 (Lexer, Parser, AST等)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 我们的第一个目标：编译出我们的自研编译器本体可执行文件
add_executable(problang-compiler ${SOURCES})

# ---------------------------------------------------------
# [注意] 未来当我们写到后端阶段时，这里会引入庞大的 LLVM 核心库
# find_package(LLVM REQUIRED CONFIG)
# message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
# ---------------------------------------------------------
