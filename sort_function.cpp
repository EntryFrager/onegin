#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "onegin_function.h"
#include "error.h"

static void swap (char **data, size_t index_1, size_t index_2);

char** bubble_sort (char **data, const size_t n_lines, int (*compare_func) (const void *str_1, const void *str_2))
{
    my_assert (data != NULL);

    for (size_t i = 0; i < n_lines; i++)
    {
        for (size_t j = 0; j < n_lines - 1; j++)
        {
            if (compare_func (data[j], data[j + 1]) > 0)
            {
                swap (data, j, j + 1);
            }
        }
    }

    return data;
}

static void swap (char **data, size_t index_1, size_t index_2)
{
    my_assert (data != NULL);

    char* t = data[index_1];

    data[index_1] = data[index_2];

    data[index_2] = t;
}