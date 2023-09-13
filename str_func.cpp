#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "onegin_function.h"
#include "error.h"

const int SIZE = 1000;

char** split_lines (char *data, const size_t size)
{   
    my_assert (data != NULL);

    char **p_buf = (char **) calloc (SIZE, sizeof(char *));

    *p_buf = data;

    int j = 1;

    for (size_t i = 0; i < size; i++)
    {
        if (*(data + i) == '\n')
        {
            *(p_buf + j) = data + (i + 1);

            *(data + i) = '\0';

            j++;
        }
    }

    return p_buf;
}

int string_cmp (const void *s1, const void *s2)
{
    my_assert (s1 != NULL);
    my_assert (s2 != NULL);

    const char *s1_new = (const char *) s1;
    const char *s2_new = (const char *) s2;

    size_t s1_len = strlen (s1_new);
    size_t s2_len = strlen (s2_new);

    while (65 >= *s1_new || (90 < *s1_new && *s1_new < 97) || *s1_new > 122)
    {
        s1_new++;
        s1_len--;
    }

    while (65 >= *s2_new || (90 < *s2_new && *s2_new < 97) || *s2_new > 122)
    {
        s2_new++;
        s2_len--;
    }

    return strcmp (s1_new, s2_new);
}

int string_cmp_reverse (const void *s1, const void *s2)
{
    my_assert (s1 != NULL);
    my_assert (s2 != NULL);

    const char *s1_new = (const char *) s1;
    const char *s2_new = (const char *) s2;

    size_t s1_len = strlen (s1_new);
    size_t s2_len = strlen (s2_new);

    while (65 >= *(s1_new + s1_len) || (90 < *(s1_new + s1_len) && *(s1_new + s1_len) < 97) || *(s1_new + s1_len) > 122)
    {
        s1_len--;
    }

    while (65 >= *(s2_new + s2_len) || (90 < *(s2_new + s2_len) && *(s2_new + s2_len) < 97) || *(s2_new + s2_len) > 122)
    {
        s2_len--;
    }

    while (strcmp((s1_new + s1_len), (s2_new + s2_len)) == 0)
    {
        s1_len--;
        s2_len--;
    }

    return strcmp((s1_new + s1_len), (s2_new + s2_len));
}