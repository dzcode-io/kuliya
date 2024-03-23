#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

#include "helpers/jsmn.h"
#include "helpers/string.h"
#include "helpers/file.h"

#define TOK_SIZE 128
#define PATH_MAX 128
#define DATA_FILE "data.h"
#define TEMP_FILE "temp.h"

static size_t max_slots_length = 0;
static char clauses[100000];

/**
 * Kuliya name.
 */
typedef struct
{
    char *ar;
    char *en;
    char *fr;
} kuliya_name;

/**
 * Kuliya terms.
 */
typedef struct
{
    int per_year;
    int *slots;
} kuliya_terms;

/**
 * Kuliya schema
 */
typedef struct
{
    kuliya_name *name;
    char *type;
    kuliya_terms *terms;
} kuliya_schema;

void parse_info_json(const char *);

/**
 * Walk `_data/` sub-directories to parse the located `info.json` file.
 * @param path Path of the `info.json` file.
 * @returns This function do not return anything.
 */
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

/**
 * Free current schema object from memory.
 * @param schema Kuliya schema object.
 * @returns This function do not return anything.
 */
void free_schema(kuliya_schema *schema)
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

/**
 * Add struct definitions at the begining of `data.h` file.
 * @returns This function do not return anything.
 */
void prepend_to_data_file()
{
    if (!FILE_EXISTS(TEMP_FILE))
        exit(EXIT_FAILURE);

    FILE *temp_file = fopen(TEMP_FILE, "r");
    if (temp_file == NULL)
        exit(EXIT_FAILURE);

    FILE *data_file = fopen(DATA_FILE, "w");
    if (data_file == NULL)
        exit(EXIT_FAILURE);

    fprintf(data_file, "// This is an auto generated file, do not edit it!\n");
    fprintf(data_file, "#ifndef DATA_H\n#define DATA_H\n");
    fprintf(data_file, "\n#include <string.h>\n");
    fprintf(data_file, "\n#define STR_EQ(str1, str2) (strcmp(str1, str2) == 0)\n");
    fprintf(data_file, "\ntypedef enum\n{\n\tUNIVERSITY,\n\tACADEMY,\n\tPRIVATE_SCHOOL,\n\tINSTITUTE,\n\tFACULTY,\n\tDEPARTMENT,\n\tSPECIALTY,\n\tSECTOR\n} node_type;\n");
    fprintf(data_file, "\ntypedef struct\n{\n\tconst char *ar;\n\tconst char *en;\n\tconst char *fr;\n} kuliya_name;\n");
    fprintf(data_file, "\ntypedef struct\n{\n\tint per_year;\n\tconst int slots[%zu];\n} kuliya_terms;\n", max_slots_length);
    fprintf(data_file, "\ntypedef struct\n{\n\tkuliya_name name;\n\tnode_type type;\n\tkuliya_terms terms;\n} kuliya_schema;\n\n");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, temp_file)) != -1)
    {
        fprintf(data_file, "%s", line);
    }

    fclose(temp_file);
    if (line)
        free(line);
    remove(TEMP_FILE);
    fclose(data_file);
}

/**
 * Add `get_node_by_path` function definition.
 * @returns This function do not return anything.
 */
void append_to_data_file()
{
    FILE *data_file = fopen(DATA_FILE, "a");
    if (data_file == NULL)
        exit(EXIT_FAILURE);

    fprintf(data_file, "\nkuliya_schema* __get_node_by_path(const char* path) {");
    fprintf(data_file, "%s\n", clauses);
    fprintf(data_file, "\treturn NULL;\n");
    fprintf(data_file, "}\n");
    fprintf(data_file, "\n#endif\n");

    fclose(data_file);
}

/**
 * Save Kuliya struct into `data.h` file.
 * @param schema Kuliya schema object.
 * @param slots_length Length of slots if the current schema has terms.
 * @param json_path Path of the `info.json` file.
 * @returns This function do not return anything.
 */
void save_to_file(const kuliya_schema *schema, const size_t slots_length, const char *json_path)
{
    FILE *data_file = fopen(TEMP_FILE, "a");
    size_t prefix_length = strlen("../_data/");
    size_t suffix_length = strlen("/info.json");
    char *path_value = (char *)json_path + prefix_length;
    path_value[strlen(path_value) - suffix_length] = '\0';
    replace_char(path_value, '/', '_');

    fprintf(data_file, "kuliya_schema %s = {.name = {.ar = \"%s\", .en = \"%s\", .fr = \"%s\"}, .type = %s ",
            path_value,
            schema->name->ar,
            schema->name->en,
            schema->name->fr,
            schema->type);

    if (schema->terms != NULL)
    {
        fprintf(data_file, ", .terms = {.per_year = %d, .slots = {%d", schema->terms->per_year, schema->terms->slots[0]);
        for (size_t i = 1; i < slots_length; i++)
        {
            fprintf(data_file, ", %d", schema->terms->slots[i]);
        }
        fprintf(data_file, "}}");
    }
    fprintf(data_file, "};\n");

    // Add condition clause for path value
    char clause[100];
    char path_name[strlen(path_value)];
    strcpy(path_name, path_value);
    replace_char(path_name, '_', '/');
    sprintf(clause, "\n\tif (STR_EQ(\"%s\", path))\n\t\treturn &%s;\n", path_name, path_value);
    strcat(clauses, clause);

    fclose(data_file);
}

/**
 * Parse the info JSON file located at a given path.
 * @param json_path Path of the `info.json` file.
 * @returns This function do not return anything.
 */
void parse_info_json(const char *json_path)
{
    // Open file in read mode
    FILE *info_json_file = fopen(json_path, "r");
    if (info_json_file != NULL)
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

        while ((c = fgetc(info_json_file)) != EOF)
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
        kuliya_schema *schema = calloc(1, sizeof(kuliya_schema));
        schema->name = calloc(1, sizeof(kuliya_name));
        schema->terms = NULL;
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
            if (STR_EQ("terms", data))
            {
                schema->terms = calloc(1, sizeof(kuliya_terms));
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
                if (s_idx > max_slots_length)
                    max_slots_length = s_idx;
                schema->terms->slots = calloc(1, s_idx * sizeof(*schema->terms->slots));
                memcpy(schema->terms->slots, tmp_slots, s_idx * sizeof(int));
            }
        }
        save_to_file(schema, s_idx, json_path);
        free_schema(schema);
    }
    else
    {
        fprintf(stderr, "not able to open file.\n");
        exit(EXIT_FAILURE);
    }

    fclose(info_json_file);
}

int main(void)
{
    if (FILE_EXISTS(DATA_FILE))
        remove(DATA_FILE);
    walk_dirs("../_data/");
    prepend_to_data_file();
    append_to_data_file();
}
