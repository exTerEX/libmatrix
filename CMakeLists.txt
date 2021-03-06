cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(
  matrix
  LANGUAGES CXX
  VERSION 0.1.0)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  set(CMAKE_SHARED_LIBRARY_SUFFIX .so)
  set(CMAKE_EXECUTABLE_SUFFIX)

  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
else()
  set(CMAKE_SHARED_LIBRARY_SUFFIX .debug.so)
  set(CMAKE_EXECUTABLE_SUFFIX .debug)

  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(CMAKE_C_CLANG_TIDY clang-tidy -checks=-*,readability-*)
endif()

add_subdirectory(src)
add_subdirectory(examples)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include(cmake/create_test.cmake)
  add_subdirectory(tests)
endif()
