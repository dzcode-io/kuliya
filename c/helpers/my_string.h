#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <string.h>
#include <stdarg.h>
#include <unistr.h>

/**
 * Perfom a string comparison between two strings.
 * @param str1 First string to be compared with.
 * @param str2 Second string to be compared with
 * @returns A boolean value that represents if the given strings are equal or not.
 */
#define STR_EQ(str1, str2) (strcmp(str1, str2) == 0)

/**
 * Check if a string is included in a given string.
 * @param big_str Big string to perform the check with.
 * @param small_str Small string to check if it's included in the big string.
 * @returns A boolean value that represetns if the big string does contain the small string.
 */
#define STR_IN(big_str, small_str) (strstr(big_str, small_str) != NULL)

/**
 * Remove characters from a given string.
 * This will modify the origin string.
 * @param str String to be modified.
 * @param c Characters to be removed from the given string.
 * @returns This function do not return anything.
 */
void remove_chars(char *str, int c, ...);

/**
 * Replace a character with another character from a given string.
 * This will modify the original string.
 * @param str String to perform the check with.
 * @param find Character to be replaced.
 * @param replace Character to replace the origin character.
 * @returns This function do not return anything.
 */
void replace_char(char *str, char find, char replace);

#endif
