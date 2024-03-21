#ifndef __FILE_H__
#define __FILE_H__

#include <unistd.h>

/**
 * Check if a file exists in a given path on Unix based system.
 * @param file_path Path of the file to check its existence.
 * @returns A boolean value that represents the existence of the file.
 */
#define FILE_EXISTS(file_path) (access(file_path, F_OK) == 0)

#endif
