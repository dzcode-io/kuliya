#include <stdio.h>
#include "kuliya.h"

/**
 * Match `node_type` enum to a string.
 * @param type Kuliya schema node type.
 * @returns String representation for the enum value.
 */
const char *match_node_type(const node_type type)
{
    switch (type)
    {
    case UNIVERSITY:
        return "UNIVERSITY";
    case ACADEMY:
        return "ACADEMY";
    case PRIVATE_SCHOOL:
        return "PRIVATE_SCHOOL";
    case INSTITUTE:
        return "INSTITUTE";
    case FACULTY:
        return "FACULTY";
    case DEPARTMENT:
        return "DEPARTMENT";
    case SPECIALTY:
        return "SPECIALTY";
    case SECTOR:
        return "SECTOR";
    }
}

/**
 * Print kuliya schema with JSON format to a file (.e.g `stdout`).
 * @param out File output.
 * @param schema Kuliya node schema.
 */
void print_kuliya_schema(FILE *out, const kuliya_schema *schema)
{
    fprintf(out, "{\n");
    fprintf(out, "\t\"name\": {\n");
    fprintf(out, "\t\t\"ar\": \"%s\",\n", schema->name.ar);
    fprintf(out, "\t\t\"en\": \"%s\",\n", schema->name.en);
    fprintf(out, "\t\t\"fr\": \"%s\"\n", schema->name.fr);
    fprintf(out, "\t},\n");
    fprintf(out, "\t\"type\": \"%s\"%s\n", match_node_type(schema->type), schema->terms != NULL ? "," : "");
    if (schema->terms != NULL)
    {
        fprintf(out, "\t\"terms\": {\n");
        fprintf(out, "\t\t\"perYear\": %d,\n", schema->terms->per_year);
        fprintf(out, "\t\t\"slots\": [%d", schema->terms->slots[0]);
        for (size_t i = 1; i < schema->terms->number_of_slots; i++)
        {
            fprintf(out, ", %d", schema->terms->slots[i]);
        }
        fprintf(out, "]\n");
        fprintf(out, "\t}\n");
    }
    fprintf(out, "}\n");
}

int main(void)
{
    kuliya_init();
    kuliya_schema *res = get_node_by_path("umkb/fst/dee/sec");
    if (res != NULL)
    {
        print_kuliya_schema(stdout, res);
    }
    kuliya_deinit();
}
