cmake_minimum_required(VERSION 3.5)

project(scl_example VERSION 0.0.1 DESCRIPTION "Simple singleton C++ logger")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main 
    example/main.cpp
    src/logger.cpp
    src/datetime.cpp
)
target_include_directories(main PRIVATE include)
target_include_directories(main PRIVATE src)
