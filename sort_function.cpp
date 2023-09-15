#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"
#include "input_print.h"
#include "error.h"

static void swap (LINE *lines, size_t index_1, size_t index_2);

char** bubble_sort (TEXT *data, int (*compare_func) (const void *str_1, const void *str_2))
{
    my_assert (data != NULL);

    for (size_t i = 0; i < data->n_lines; i++)
    {
        for (size_t j = 0; j < data->n_lines - 1; j++)
        {
            if (compare_func (&data->lines[j], &data->lines[j + 1]) > 0)
            {
                swap (data->lines, j, j + 1);
            }
        }
    }
}

/*void my_qsort (void *text, size_t n_lines, size_t size_elements, int (*compare_func) (const void *str_1, const void *str_2))
{
    my_assert (text != NULL);

    size_t left = 0;
    size_t right = n_lines - 1;

    size_t pivot = (left + right) / 2;

    while (left++ <= pivot && right-- >= pivot)
    {
        if (left + 1 < pivot
    }
    
    my_qsort ();
}*/

static void swap (LINE *lines, size_t index_1, size_t index_2)
{
    my_assert (lines != NULL);

    LINE lines_tmp= lines[index_1];

    lines[index_1] = lines[index_2];
    lines[index_2] = lines_tmp;
}