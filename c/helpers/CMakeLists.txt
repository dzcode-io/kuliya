add_library(helpers SHARED file.h my_string.h my_string.c)
set_target_properties(helpers PROPERTIES LINKER_LANGUAGE C)
find_package(libunistring REQUIRED)
target_link_libraries(helpers PRIVATE libunistring::libunistring)
