cmake_minimum_required(VERSION 3.20)
project(tutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_library(algebra lib/algebra.cc)
# target_include_directories(algebra PUBLIC include)

# add_executable(hello src/hello.cc)
# target_link_libraries(hello algebra)

add_executable(main src/main.cc)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)