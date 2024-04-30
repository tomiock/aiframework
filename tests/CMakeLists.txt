enable_testing()
find_package(GTest REQUIRED)

add_executable(test_ops test_ops.cpp)
target_link_libraries(test_ops ${GTEST_BOTH_LIBRARIES} tensor ops_tensor)

gtest_discover_tests(test_ops)
