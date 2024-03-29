cmake_minimum_required(VERSION 3.19)
project(kuliya)

include_directories(.)

add_library(kuliya SHARED kuliya.h)
set_target_properties(kuliya PROPERTIES LINKER_LANGUAGE C)

add_executable(test test/test.c)
add_executable(example example/main.c)
add_executable(build build.c)

target_link_libraries(test kuliya)
target_link_libraries(example kuliya)
