#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <jsmn.h>

#include "helpers/my_string.h"
#include "helpers/file.h"

#define TOK_SIZE 128
#define __PATH_MAX 128
#define DATA_FILE "data.h"
#define TEMP_FILE "temp.h"

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

typedef struct
{
    kuliya_terms terms;
    char *__varname;
    size_t __slots_length;
} __s_kuliya_schema;

static size_t kuliya_with_terms_idx = 0;
static __s_kuliya_schema kuliyas_with_terms[1000];

void parse_info_json(const unsigned char *);

/**
 * Walk `_data/` sub-directories to parse the located `info.json` file.
 * @param path Path of the `info.json` file.
 * @returns This function do not return anything.
 */
void walk_dirs(const unsigned char *path)
{
    struct dirent *dent;
    DIR *srcdir = opendir((const char *)path);

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
            unsigned char tmp_path[__PATH_MAX];
            u8_strcpy(tmp_path, path);
            u8_strcat(tmp_path, (const unsigned char *)dent->d_name);
            u8_strcat(tmp_path, (const unsigned char *)"/");
            unsigned char info_path[__PATH_MAX];
            u8_strcpy(info_path, tmp_path);
            u8_strcat(info_path, (const unsigned char *)"info.json");
            if (FILE_EXISTS((const char *)info_path))
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
    fprintf(data_file, "\n#include <stdlib.h>\n#include <string.h>\n");
    fprintf(data_file, "\n#define STR_EQ(str1, str2) (strcmp(str1, str2) == 0)\n");
    fprintf(data_file, "\n/**\n * Node type.\n */\ntypedef enum\n{\n\t/** University. */\n\tUNIVERSITY,\n\t/** Academy. */\n\tACADEMY,\n\t/** Private school. */\n\tPRIVATE_SCHOOL,\n\t/** Institute */\n\tINSTITUTE,\n\t/** Faculty */\n\tFACULTY,\n\t/** Department */\n\tDEPARTMENT,\n\t/** Specialty. */\n\tSPECIALTY,\n\t/** Sector. */\n\tSECTOR\n} node_type;\n");
    fprintf(data_file, "\n/**\n * Kuliya names in Arabic, English and French.\n */\ntypedef struct\n{\n\t/** Arabic name. */\n\tconst char *ar;\n\t/** English name. */\n\tconst char *en;\n\t/** French name. */\n\tconst char *fr;\n} kuliya_name;\n");
    fprintf(data_file, "\n/**\n * Kuliya terms.\n */\ntypedef struct\n{\n\t/** Slots per year. */\n\tint per_year;\n\t/** Slots. */\n\tint *slots;\n\t/** Number of slots. */\n\tsize_t number_of_slots;\n} kuliya_terms;\n");
    fprintf(data_file, "\n/**\n * Kuliya schema.\n */\ntypedef struct\n{\n\t/** Name. */\n\tkuliya_name name;\n\t/** Node type. */\n\tnode_type type;\n\t/** Terms. */\n\tkuliya_terms *terms;\n} kuliya_schema;\n\n");

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

    // Add init function to allocate memory for necessary heap allocated data
    fprintf(data_file, "\nstatic void __kuliya_init()\n{\n");
    for (size_t i = 0; i < kuliya_with_terms_idx; ++i)
    {
        __s_kuliya_schema schema = kuliyas_with_terms[i];
        fprintf(data_file, "\t%s.terms = (kuliya_terms *)malloc(sizeof(kuliya_terms));\n", schema.__varname);
        fprintf(data_file, "\t%s.terms->per_year = %d;\n", schema.__varname, schema.terms.per_year);
        fprintf(data_file, "\t%s.terms->number_of_slots = %zu;\n", schema.__varname, schema.__slots_length);
        fprintf(data_file, "\t%s.terms->slots = (int *)malloc(%zu * sizeof(int));\n", schema.__varname, schema.__slots_length);
        for (size_t j = 0; j < schema.__slots_length; ++j)
        {
            fprintf(data_file, "\t%s.terms->slots[%zu] = %d;\n", schema.__varname, j, schema.terms.slots[j]);
        }
    }
    fprintf(data_file, "}\n");

    // Add deinit function to free heap allocated data
    fprintf(data_file, "\nstatic void __kuliya_deinit()\n{\n");
    for (size_t i = 0; i < kuliya_with_terms_idx; ++i)
    {
        __s_kuliya_schema schema = kuliyas_with_terms[i];
        fprintf(data_file, "\tfree(%s.terms->slots);\n", schema.__varname);
        fprintf(data_file, "\tfree(%s.terms);\n", schema.__varname);
    }
    fprintf(data_file, "}\n");

    // Prepare get node by path API
    fprintf(data_file, "\nstatic kuliya_schema *__get_node_by_path(const char *path)\n{");
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
void save_to_file(kuliya_schema *schema, const size_t slots_length, const unsigned char *json_path)
{
    FILE *data_file = fopen(TEMP_FILE, "a");
    size_t prefix_length = strlen("../_data/");
    size_t suffix_length = strlen("/info.json");
    unsigned char *path_value = (unsigned char *)json_path + prefix_length;
    path_value[u8_strlen(path_value) - suffix_length] = '\0';
    replace_char(path_value, '/', '_');

    fprintf(data_file, "static kuliya_schema %s = {.name = {.ar = \"%s\", .en = \"%s\", .fr = \"%s\"}, .type = %s, .terms = NULL};\n",
            path_value,
            schema->name->ar,
            schema->name->en,
            schema->name->fr,
            schema->type);

    if (schema->terms != NULL)
    {
        size_t varname_length = u8_strlen(path_value);
        kuliyas_with_terms[kuliya_with_terms_idx].__varname = malloc(varname_length + 1);
        memcpy(kuliyas_with_terms[kuliya_with_terms_idx].__varname, path_value, varname_length);
        kuliyas_with_terms[kuliya_with_terms_idx]
            .__varname[varname_length] = '\0';
        kuliyas_with_terms[kuliya_with_terms_idx]
            .__slots_length = slots_length;
        kuliyas_with_terms[kuliya_with_terms_idx].terms.per_year = schema->terms->per_year;
        kuliyas_with_terms[kuliya_with_terms_idx].terms.slots = malloc(slots_length * sizeof(int));
        memcpy(kuliyas_with_terms[kuliya_with_terms_idx].terms.slots, schema->terms->slots, slots_length * sizeof(int));
        kuliya_with_terms_idx++;
    }

    // Add condition clause for path value
    char clause[100];
    unsigned char path_name[u8_strlen(path_value)];
    u8_strcpy(path_name, path_value);
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
void parse_info_json(const unsigned char *json_path)
{
    // Open file in read mode
    FILE *info_json_file = fopen((const char *)json_path, "r");
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
            unsigned char data[length + 1];
            memcpy(data, &buf[token->start], length);
            data[length] = '\0';
            if (STR_EQ("ar", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->name->ar = calloc(1, length + 1);
                memcpy(schema->name->ar, data, length + 1);
            }
            if (STR_EQ("en", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->name->en = calloc(1, length + 1);
                memcpy(schema->name->en, data, length + 1);
            }
            if (STR_EQ("fr", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->name->fr = calloc(1, length + 1);
                memcpy(schema->name->fr, data, length + 1);
            }
            if (STR_EQ("type", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->type = calloc(1, length + 1);
                memcpy(schema->type, data, length + 1);
            }
            if (STR_EQ("terms", (char *)data))
            {
                schema->terms = calloc(1, sizeof(kuliya_terms));
            }
            if (STR_EQ("perYear", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                schema->terms->per_year = atoi(data);
            }
            if (STR_EQ("slots", (char *)data))
            {
                token = &tokens[i + 1];
                unsigned int length = token->end - token->start;
                unsigned char data[length + 1];
                memcpy(data, &buf[token->start], length);
                data[length] = '\0';
                remove_chars(data, '[', ']', ' ');
                unsigned char *rest = data;
                unsigned char *ptr = u8_strtok(data, (unsigned char *)",", &rest);
                int tmp_slots[50];
                while (ptr != NULL)
                {
                    int val = atoi((const char *)ptr);
                    tmp_slots[s_idx++] = val;
                    ptr = u8_strtok(NULL, (unsigned char *)",", &rest);
                }
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
    walk_dirs((const unsigned char *)"../_data/");
    prepend_to_data_file();
    append_to_data_file();
}
