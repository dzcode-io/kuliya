#ifndef KULIYA_H
#define KULIYA_H

#include "data.h"

#define KULIYA_API extern

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Get kuliya schema node by a given path.
     * @param path Kuliya path based on the location for `info.json` file in `_data/` folder (.eg `"usto/fmi"`).
     * @returns Pointer to kuliya schema if the path exists, else a NULL pointer.
     */
    KULIYA_API kuliya_schema *get_node_by_path(const char *path)
    {
        return __get_node_by_path(path);
    }

#ifdef __cplusplus
}
#endif

#endif /* KULIYA_H */
