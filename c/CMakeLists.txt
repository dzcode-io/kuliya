cmake_minimum_required(VERSION 3.19)
project(kuliya)

include_directories(.)
include_directories(helpers)

# Add the helpers subdirectory
add_subdirectory(helpers)

# Create the build executable
add_executable(build build.c)

# Add a custom target that depends on the 'build' target
add_custom_target(run_build
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/build
    DEPENDS build
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running build executable"
)

# Create the shared library "kuliya"
add_library(kuliya SHARED kuliya.h)

# Set the linker language to C
set_target_properties(kuliya PROPERTIES LINKER_LANGUAGE C)

# Create the test executable
add_executable(test test/test.cpp)

# Create the example executable
add_executable(example example/main.c)
add_executable(example2 example/main.cpp)


# Link the example executable with the "kuliya" library
target_link_libraries(example kuliya)
target_link_libraries(example2 kuliya)

# Link the build and test executables with the "helpers" library
target_link_libraries(build helpers)

# Find and link the jsmn library
find_package(jsmn REQUIRED)
target_link_libraries(build jsmn::jsmn)

# Link the "helpers" shared library with libunistring
find_package(libunistring REQUIRED)
target_link_libraries(build libunistring::libunistring)

# Link test executable with required libraries
find_package(CppUTest REQUIRED)
target_link_libraries(test PRIVATE kuliya helpers cpputest::cpputest libunistring::libunistring)

# Make all targets depend on the 'run_build' target, which in itself depends on the 'build' target
add_dependencies(kuliya run_build)
add_dependencies(test run_build)
add_dependencies(example run_build)
add_dependencies(example2 run_build)
# Print a success message
message("CMakeLists.txt updated successfully.")
