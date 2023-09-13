#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "onegin_function.h"
#include "error.h"

size_t get_file_size (FILE *stream)
{
    my_assert (stream != NULL);

    fseek (stream, 0L, SEEK_END);

    size_t size_file = ftell (stream);

    rewind (stream);

    return size_file;
}

size_t number_of_lines (const char *data, const size_t size)
{
    size_t n = 1;

    for (size_t i = 0; i < size; i++)
    {
        if (data[i] == '\n')
        {
            n++;
        }
    }

    return n;
}
