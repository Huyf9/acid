cmake_minimum_required(VERSION 3.10)
project(acid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(LIB_NAME acid)
set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})

option(BUILD_TEST "Build test." ON)
option(INSTALL_TEST "Install test." ON)

add_compile_options(-fPIC)
add_compile_options(-Wno-unused-variable)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${THIRD_PARTY}/mimalloc/include)
if (BUILD_TEST)
    include_directories(${THIRD_PARTY}/googletest/googletest/include)
    add_subdirectory(${THIRD_PARTY}/googletest)
endif()

file(GLOB_RECURSE CSRCS ${CMAKE_CURRENT_SOURCE_DIR}/acid/*.cpp)

add_subdirectory(${THIRD_PARTY}/mimalloc)

add_library(${LIB_NAME} SHARED ${CSRCS})

target_link_libraries(
    ${LIB_NAME}
    PRIVATE
    mimalloc-static)

set_target_properties(
    ${LIB_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_subdirectory(tests)
