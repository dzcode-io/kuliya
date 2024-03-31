add_library(helpers SHARED file.h my_string.h my_string.c)
set_target_properties(helpers PROPERTIES LINKER_LANGUAGE C)
