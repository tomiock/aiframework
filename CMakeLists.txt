cmake_minimum_required(VERSION 3.4)

project(
    aiframework
    VERSION 0.1
)

include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)
