# Add all the source files
set(SOURCES main.c tensor.c ops_tensor.c)

# Add the include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create an executable with a specific output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/..)
add_executable(your_executable_name ${SOURCES})
