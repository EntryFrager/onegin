#include <stdio.h>
#include <stdlib.h>

#include "input_print.h"
#include "function.h"
#include "error.h"

int main ()
{
    TEXT data = {};

    int code_error = input_text (&data);

    if (code_error != 0)
    {
        fprintf(stderr, "%s", my_strerr (code_error));
    }

    data.file_name_print = "onegin_print.txt";

    data.fp_print = fopen (data.file_name_print, "r+");

    if (data.fp_print == NULL)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FOPEN));
    }

    my_qsort (data.lines, 0, data.n_lines - 1, string_cmp);
    print_sort_text (&data);

    qsort (data.lines, data.n_lines, sizeof (LINE), string_cmp);
    print_sort_text (&data);
    
    print_text (&data);

    if (fclose (data.fp_print) != 0)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FCLOSE));
    }

    free_ptr (&data);

    return 0;
}