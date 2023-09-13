#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "onegin_input_print.h"
#include "error.h"

char* onegin_input (FILE *stream, const size_t size_file)
{
    my_assert (stream != NULL);

    char* data = (char *) calloc (size_file + 1, sizeof (char));

    fread (data, sizeof (char), size_file, stream);

    *(data + size_file) = '\0';

    return data;
}

void onegin_print (const char **data, const size_t n_lines, FILE *stream)
{
    my_assert (data != NULL);

    for (int i = 0; i < n_lines; i++)
    {
        fprintf (stream, "%s", data[i]);
    }

    fprintf (stream, "\n\n\n");
}