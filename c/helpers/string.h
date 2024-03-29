#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include <stdarg.h>

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
void remove_chars(char *str, int c, ...)
{
    va_list args;
    va_start(args, c);

    while (42) // The answer for everything
    {
        char char_to_remove = va_arg(args, int);
        if (char_to_remove == '\0')
            break;

        size_t j = 0;
        for (size_t i = 0; i < str[i] != '\0'; ++i)
        {
            if (str[i] != char_to_remove)
                str[j++] = str[i];
        }
        str[j] = '\0';
    }

    va_end(args);

    // This is to confirm deleting the first vararg character
    size_t j = 0;
    for (size_t i = 0; i < str[i] != '\0'; ++i)
    {
        if (str[i] != c)
            str[j++] = str[i];
    }
    str[j] = '\0';
}

/**
 * Replace a character with another character from a given string.
 * This will modify the original string.
 * @param str String to perform the check with.
 * @param find Character to be replaced.
 * @param replace Character to replace the origin character.
 * @returns This function do not return anything.
 */
void replace_char(char *str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
}

#endif
