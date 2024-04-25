enable_testing()
find_package(GTest REQUIRED)

add_executable(test_test test_test.cpp)
target_link_libraries(test_test ${GTEST_BOTH_LIBRARIES} SRC)

gtest_discover_tests(test_test)
