find_package(Boost 1.70.0 REQUIRED COMPONENTS iostreams)
add_executable(main main.cpp)
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 11)
target_link_libraries(main ${PROJECT_NAME} Boost::iostreams)
