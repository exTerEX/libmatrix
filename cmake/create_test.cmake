macro(create_test target)
  string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" file ${target})
  add_executable(${file} ${file}.cpp)
  target_link_libraries(${file} ${PROJECT_NAME})
  add_test(
    ${file} ${file}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND $<TARGET_FILE:${file}>)
  set_tests_properties(
    ${file} PROPERTIES FAIL_REGULAR_EXPRESSION "(Exception|Assertion|failed.)"
                       TIMEOUT 120)
endmacro(create_test)
