include(CTest)

# test_block
add_executable(test_matrix test_matrix.cpp)
target_link_libraries(test_matrix ${PROJECT_NAME})
add_test(test_matrix test_matrix)
set_tests_properties(
  test_matrix PROPERTIES FAIL_REGULAR_EXPRESSION "(Exception|Assertion|failed.)"
                        TIMEOUT 120)
