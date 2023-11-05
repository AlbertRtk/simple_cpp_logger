add_library(SimpleCppLogger logger.cpp datetime.cpp)
target_include_directories(SimpleCppLogger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})