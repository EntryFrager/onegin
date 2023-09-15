#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "function.h"
#include "error.h"

const int SIZE = 1000;

static size_t number_of_lines (const char *data, const size_t size);

void split_lines (TEXT *data)
{   
    my_assert (data != NULL);

    data->n_lines =  number_of_lines (data->buf, data->size_file);

    data->lines = (LINE *) calloc (data->n_lines, sizeof(LINE));
    my_assert (data->lines != NULL);

    data->text = (char **) calloc (SIZE, sizeof(char *));
    my_assert (data->text != NULL);

    *data->text = data->buf;
    (data->lines)[0].str = data->buf;
    (data->lines)[0].size_str = 1;
    int j = 1;

    for (size_t id = 1; id <= data->size_file; id++)
    {
        if (data->buf[id] == '\n' && data->buf[id - 1] != '\n')
        {
            *(data->buf + id) = '\0';
            
            (data->lines)[j].str = data->buf + (id + 1);

            j++;
        }
        else
        {
            (data->lines)[j - 1].size_str++;
        }
    }   
}

int string_cmp (const void *s1, const void *s2)
{
    my_assert (s1 != NULL);
    my_assert (s2 != NULL);

    LINE s1_new = *((LINE *) s1);
    LINE s2_new = *((LINE *) s2);

    size_t i_1 = 0;
    size_t i_2 = 0;

    while (!isalpha (*(s1_new.str)))
    {
        s1_new.str++;
    }

    while (!isalpha (*(s2_new.str)))
    {
        s2_new.str++;
    }

    if (s1_new.size_str < s2_new.size_str)
    {
        return strncmp (s1_new.str, s2_new.str, s1_new.size_str);
    }

    return strncmp (s1_new.str, s2_new.str, s2_new.size_str);
}

int string_cmp_reverse (const void *s1, const void *s2)
{
    my_assert (s1 != NULL);
    my_assert (s2 != NULL);

    LINE s1_new = *(LINE *) s1;
    LINE s2_new = *(LINE *) s2;

    while (!isalpha (*(s1_new.str + s1_new.size_str)))
    {
        s1_new.size_str--;
    }

    while (!isalpha (*(s2_new.str + s2_new.size_str)))
    {
        s2_new.size_str--;
    }

    while (*(s1_new.str + s1_new.size_str) == *(s2_new.str + s2_new.size_str))
    {
        s1_new.size_str--;
        s2_new.size_str--;
    }

    if (s1_new.size_str == 0 && s2_new.size_str == 0)
    {
        return 0;
    }

    return *(s1_new.str + s1_new.size_str) - *(s2_new.str + s2_new.size_str);
}

static size_t number_of_lines (const char *data, const size_t size)
{
    my_assert (data != NULL);

    size_t n = 1;

    for (size_t i = 1; i < size; i++)
    {
        if (data[i] == '\n' && data[i - 1] != '\n')
        {
            n++;
        }
    }

    return n;
}

void free_ptr (TEXT *data)
{
    my_assert (data != NULL);

    free (data->buf);
    free (data->text);
}