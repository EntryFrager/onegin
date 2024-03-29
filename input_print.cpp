#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_print.h"
#include "error.h"

int input_text (TEXT* data)
{
    my_assert (data != NULL);

    data->file_name_input = (const char *) "Onegin.txt";

    data->fp_input = fopen (data->file_name_input, "rb");

    if (data->fp_input == NULL)
    {
        return ERR_FOPEN;
    }

    data->size_file = get_file_size (data->fp_input);

    data->buf = (char *) calloc (data->size_file + 1, sizeof (char));
    my_assert (data->buf != NULL);

    size_t read_size = fread (data->buf, sizeof (char), data->size_file, data->fp_input);

    if (read_size != data->size_file)
    {
        return ERR_FREAD;
    }

    *(data->buf + data->size_file) = '\0';

    if (fclose (data->fp_input) != 0)
    {
        return ERR_FCLOSE;
    }

    split_lines (data);

    return ERR_NO;
}

void print_sort_text (TEXT* data)
{
    my_assert (data != NULL);

    for (size_t i = 0; i < data->n_lines; i++)
    {
        my_assert (data->lines[i].str != NULL);

        fprintf (data->fp_print, "%s\n", data->lines[i].str);
    }

    fprintf (data->fp_print, "\n\n\n");
}

void print_text (TEXT *data)
{
    my_assert (data != NULL);

    size_t len = 0;

    for (size_t i = 0; i <= data->size_file; i++)
    {
        if (*data->buf++ == '\0')
        {
            fprintf (data->fp_print, "%s\n", data->buf - len - 1);
            len = 0;
        }
        else 
        {
            len++;
        }
    }
}

size_t get_file_size (FILE *stream)
{
    my_assert (stream != NULL);

    size_t start = ftell (stream);
    fseek (stream, start, SEEK_END);
    size_t size_file = ftell (stream);
    rewind (stream);

    return size_file;
}