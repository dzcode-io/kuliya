#include "my_string.h"

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
        for (size_t i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] != char_to_remove)
                str[j++] = str[i];
        }
        str[j] = '\0';
    }

    va_end(args);
}

void replace_char(unistring_uint8_t *str, unistring_uint8_t find, unistring_uint8_t replace)
{
    unistring_uint8_t *current_pos = u8_strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = u8_strchr(current_pos, find);
    }
}
