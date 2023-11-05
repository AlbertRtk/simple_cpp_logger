cmake_minimum_required(VERSION 3.5)

project(scl_example VERSION 0.0.1 DESCRIPTION "Simple singleton C++ logger")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(main example/main.cpp)

target_link_libraries(main PUBLIC SimpleCppLogger)
