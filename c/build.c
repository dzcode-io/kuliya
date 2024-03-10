#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "helpers/jsmn.h"

#define TOK_SIZE 128
#define STR_EQ(str1, str2) strcmp(str1, str2) == 0
#define STR_IN(big_str, small_str) strstr(big_str, small_str) != NULL

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

int main(void)
{
    // Open file in read mode
    FILE *file = fopen("../_data/umkb/fst/dee/sec/info.json", "r");
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

        jsmntok_t *token;
        schema *schema;
        schema = calloc(1, sizeof(schema));
        schema->name = calloc(1, sizeof(kuliya_name));
        schema->terms = calloc(1, sizeof(kuliya_terms));
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
                schema->name->ar = calloc(1, length + 1);
                memcpy(schema->name->ar, data, length + 1);
            }
            if (STR_EQ("en", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->name->en = calloc(1, length + 1);
                memcpy(schema->name->en, data, length + 1);
            }
            if (STR_EQ("fr", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->name->fr = calloc(1, length + 1);
                memcpy(schema->name->fr, data, length + 1);
            }
            if (STR_EQ("type", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->type = calloc(1, length + 1);
                memcpy(schema->type, data, length + 1);
            }
            if (STR_EQ("perYear", data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->terms->per_year = atoi(data);
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
                schema->terms->slots = calloc(1, s_idx * sizeof(*schema->terms->slots));
                memcpy(schema->terms->slots, tmp_slots, s_idx * sizeof(int));
            }
        }
        print_schema(schema, s_idx);
        free_schema(schema);
    }
    else
    {
        fprintf(stderr, "not able to open file.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}
