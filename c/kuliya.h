#ifndef KULIYA_H
#define KULIYA_H

#include "data.h"

#define KULIYA_API extern

#ifdef __cplusplus
extern "C"
{
#endif

    KULIYA_API kuliya_schema *get_node_by_path(const char *path)
    {
        return __get_node_by_path(path);
    }

#ifdef __cplusplus
}
#endif

#endif /* KULIYA_H */
