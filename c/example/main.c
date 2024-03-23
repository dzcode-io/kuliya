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
 * Print kuliya schema with JSON format in `stdout`.
 * @param schema Kuliya node schema.
 */
void print_kuliya_schema(const kuliya_schema *schema)
{
    printf("{\n");
    printf("\t\"name\": {\n");
    printf("\t\t\"ar\": \"%s\",\n", schema->name.ar);
    printf("\t\t\"en\": \"%s\",\n", schema->name.en);
    printf("\t\t\"fr\": \"%s\"\n", schema->name.fr);
    printf("\t},\n");
    printf("\t\"type\": \"%s\",\n", match_node_type(schema->type));
    printf("\t\"terms\": {\n");
    printf("\t\t\"per_year\": %d,\n", schema->terms.per_year);
    printf("\t\t\"slots\": [%d", schema->terms.slots[0]);
    for (size_t i = 1; i < 4; i++)
    {
        printf(", %d", schema->terms.slots[i]);
    }
    printf("]\n");
    printf("\t}\n");
    printf("}\n");
}

int main(void)
{
    kuliya_schema *res = get_node_by_path("umkb/fst/dee/sec");
    if (res != NULL)
    {
        print_kuliya_schema(res);
    }
}
