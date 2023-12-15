cmake_minimum_required(VERSION 3.1)

project(
	mycblastest
	VERSION 1.0
	)

include_directories(include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(BLAS REQUIRED)

add_executable(test test.cpp)
target_link_libraries(test PUBLIC ${BLAS_LIBRARIES})

