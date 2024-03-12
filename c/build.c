#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

#include "helpers/jsmn.h"

#define TOK_SIZE 128
#define PATH_MAX 128
#define STR_EQ(str1, str2) strcmp(str1, str2) == 0
#define STR_IN(big_str, small_str) strstr(big_str, small_str) != NULL
#define FILE_EXISTS(file_path) access(file_path, F_OK) == 0

typedef struct
{
    char *ar;
    char *en;
    char *fr;
} kuliya_name;

typedef struct
{
    int per_year;
    int *slots;
} kuliya_terms;

typedef struct
{
    kuliya_name *name;
    char *type;
    kuliya_terms *terms;
} schema;

void parse_info_json(const char *json_path);

void remove_chars(char *str, int c, ...)
{
    va_list args;
    va_start(args, c);

    while (42) // The answer for everything
    {
        char char_to_remove = va_arg(args, int);
        if (char_to_remove == '\0')
            break;

        int j = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] != char_to_remove)
                str[j++] = str[i];
        }
        str[j] = '\0';
    }

    va_end(args);
}

void walk_dirs(const char *path)
{
    struct dirent *dent;
    DIR *srcdir = opendir(path);

    if (srcdir == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dent = readdir(srcdir)) != NULL)
    {
        struct stat st;

        if (STR_EQ(dent->d_name, ".") || STR_EQ(dent->d_name, ".."))
            continue;

        if (fstatat(dirfd(srcdir), dent->d_name, &st, 0) < 0)
        {
            perror(dent->d_name);
            continue;
        }

        if (S_ISDIR(st.st_mode))
        {
            char tmp_path[PATH_MAX];
            strcpy(tmp_path, path);
            strcat(tmp_path, dent->d_name);
            strcat(tmp_path, "/");
            char info_path[PATH_MAX];
            strcpy(info_path, tmp_path);
            strcat(info_path, "info.json");
            if (FILE_EXISTS(info_path))
                parse_info_json(info_path);
            walk_dirs(tmp_path);
        }
    }
    closedir(srcdir);
}

void free_schema(schema *schema)
{
    free(schema->name->ar);
    free(schema->name->en);
    free(schema->name->fr);
    free(schema->name);
    free(schema->type);
    if (schema->terms != NULL)
    {
        free(schema->terms->slots);
        free(schema->terms);
    }
    free(schema);
}

void print_schema(const schema *schema, const size_t slots_length)
{
    printf("------------------------------------\n");
    printf("name ar: \"%s\"\n", schema->name->ar);
    printf("name en: \"%s\"\n", schema->name->en);
    printf("name fr: \"%s\"\n", schema->name->fr);
    printf("type: \"%s\"\n", schema->type);
    if (schema->terms != NULL)
    {
        printf("terms per_year: %d\n", schema->terms->per_year);
        printf("terms slots: [%d", schema->terms->slots[0]);
        for (size_t i = 1; i < slots_length; i++)
        {
            printf(", %d", schema->terms->slots[i]);
        }
        printf("]\n");
    }
    printf("------------------------------------\n");
}

void parse_info_json(const char *json_path)
{
    // Open file in read mode
    FILE *file = fopen(json_path, "r");
    if (file != NULL)
    {
        // Read file content into a dynamically allocated buffer
        int c;
        int nch = 0;
        size_t size = 10;
        char *buf = malloc(size);
        if (buf == NULL)
        {
            fprintf(stderr, "out of memory\n");
            exit(EXIT_FAILURE);
        }

        while ((c = fgetc(file)) != EOF)
        {
            if (nch >= size - 1)
            {
                size += 10;
                buf = realloc(buf, size);
                if (buf == NULL)
                {
                    fprintf(stderr, "out of memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            buf[nch++] = c;
        }
        buf[nch++] = '\0';

        // Parse json
        jsmn_parser p;
        jsmntok_t tokens[TOK_SIZE];

        jsmn_init(&p);
        int number_of_tokens = jsmn_parse(&p, buf, strlen(buf), tokens, TOK_SIZE);

        jsmntok_t *token = calloc(1, sizeof(jsmntok_t));
        schema *s = calloc(1, sizeof(schema));
        s->name = calloc(1, sizeof(kuliya_name));
        s->terms = NULL;
        size_t s_idx = 0;
        for (size_t i = 0; i < number_of_tokens; ++i)
        {
            token = &tokens[i];
            unsigned int length = token->end - token->start;
            char data[length + 1];
            memcpy(data, &buf[token->start], length);
            data[length] = '\0';
            if (STR_EQ("ar", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                s->name->ar = calloc(1, length + 1);
                memcpy(s->name->ar, data, length + 1);
            }
            if (STR_EQ("en", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                s->name->en = calloc(1, length + 1);
                memcpy(s->name->en, data, length + 1);
            }
            if (STR_EQ("fr", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                s->name->fr = calloc(1, length + 1);
                memcpy(s->name->fr, data, length + 1);
            }
            if (STR_EQ("type", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                s->type = calloc(1, length + 1);
                memcpy(s->type, data, length + 1);
            }
            if (STR_EQ("terms", data))
            {
                s->terms = calloc(1, sizeof(kuliya_terms));
            }
            if (STR_EQ("perYear", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                s->terms->per_year = atoi(data);
            }
            if (STR_EQ("slots", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                remove_chars(data, '[', ']', ' ');
                char *ptr = strtok(data, ",");
                int tmp_slots[50];
                while (ptr != NULL)
                {
                    int val = atoi(ptr);
                    tmp_slots[s_idx++] = val;
                    ptr = strtok(NULL, ",");
                }
                s->terms->slots = calloc(1, s_idx * sizeof(*s->terms->slots));
                memcpy(s->terms->slots, tmp_slots, s_idx * sizeof(int));
            }
        }
        print_schema(s, s_idx);
        free_schema(s);
    }
    else
    {
        fprintf(stderr, "not able to open file.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main(void)
{
    walk_dirs("../_data/");
}
