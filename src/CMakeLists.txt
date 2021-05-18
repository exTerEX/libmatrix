add_library(${PROJECT_NAME} SHARED matrix.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include>)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES LINKER_LANGUAGE CXX
             PREFIX lib
             CXX_STANDARD 11)