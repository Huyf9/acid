cmake_minimum_required(VERSION 3.10)
project(acid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(LIB_NAME acid)

option(BUILD_TEST "Build test." ON)

add_compile_options(-fPIC)
add_compile_options(-Wno-unused-variable)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE CSRCS ${CMAKE_CURRENT_SOURCE_DIR}/acid/*.cpp)

add_library(${LIB_NAME} SHARED ${CSRCS})
