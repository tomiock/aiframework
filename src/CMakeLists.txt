# Add all the source files
set(SOURCES main.c tensor.c ops_tensor.c)

<<<<<<< HEAD
=======
add_library(ops_tensor SHARED ops_tensor.c)
add_library(tensor SHARED tensor.c)

>>>>>>> 3285d66 (many changes)
# Add the include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create an executable with a specific output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/..)
<<<<<<< HEAD
add_executable(your_executable_name ${SOURCES})
=======
add_executable(main ${SOURCES})
>>>>>>> 3285d66 (many changes)
