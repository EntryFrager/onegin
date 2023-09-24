#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"
#include "input_print.h"
#include "error.h"

static void swap (void *text_1, void *text_2);

#if 0
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

#endif

void my_qsort (void *line_1, size_t first, size_t last, int (*compare_func) (const void *str_1, const void *str_2))
{
    my_assert (line_1 != NULL);

    LINE *lines = (LINE *) line_1;

    if (first >= last)
    {
        return;
    }

    size_t left = first;
    size_t right = last;

    size_t pivot = (left + right) / 2;

    while (left <= right)
    {
        while (compare_func (&lines[left], &lines[pivot]) < 0 && left <= right)
        {
            left++;
        }
        while (compare_func (&lines[pivot], &lines[right]) < 0 && right >= 0)
        {
            right--;
        }

        if (left >= right)
        {
            break;
        }
        
        swap (&lines[left], &lines[right]);
        left++;
        right--;
    }
    
    my_qsort (lines, first, right, compare_func);

    my_qsort (lines, left + 1, last, compare_func);
}

static void swap (void *text_1, void *text_2)
{
    my_assert (text_1 != NULL);
    my_assert (text_2 != NULL);


    LINE *str_1 = (LINE *) text_1;
    LINE *str_2 = (LINE *) text_2;

    LINE lines_tmp = *str_1;

    *str_1 = *str_2;
    *str_2 = lines_tmp;
}