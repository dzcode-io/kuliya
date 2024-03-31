cmake_minimum_required(VERSION 3.19)
project(kuliya)

include_directories(.)
include_directories(helpers)

# Add the helpers subdirectory
add_subdirectory(helpers)

# Create the shared library "kuliya"
add_library(kuliya SHARED kuliya.h)

# Set the linker language to C
set_target_properties(kuliya PROPERTIES LINKER_LANGUAGE C)

# Create the test executable
add_executable(test test/test.c)

# Create the example executable
add_executable(example example/main.c)

# Create the build executable
add_executable(build build.c)

# Link the test and example executables with the "kuliya" library
target_link_libraries(test kuliya)
target_link_libraries(example kuliya)

# Link the build and test executables with the "helpers" library
target_link_libraries(build helpers)
target_link_libraries(test helpers)

# Find and link the jsmn library
find_package(jsmn REQUIRED)
target_link_libraries(build jsmn::jsmn)

# Link the "helpers" shared library with libunistring
find_package(libunistring REQUIRED)
target_link_libraries(helpers PRIVATE libunistring::libunistring)
target_link_libraries(test libunistring::libunistring)
target_link_libraries(build libunistring::libunistring)

# Print a success message
message("CMakeLists.txt updated successfully.")
