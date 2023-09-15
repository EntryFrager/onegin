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

    data.fp_print = fopen (data.file_name_print, "r+");

    if (data.fp_print == NULL)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FOPEN));
    }

    //Первый вид сортировки - сортирует в алфавитном порядке по первым буквам

    qsort (data.lines, data.n_lines - 1, sizeof(LINE *), string_cmp);
    print_sort_text (&data);

    //Второй вид сортировки - сортирует в алфавитном порядке, но по последним буквам

    bubble_sort (&data, string_cmp_reverse);
    print_sort_text (&data);

    //Обычный вывод - без сортировки, дефолтный текст из файла

    print_text (&data);

    if (fclose (data.fp_print) != 0)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FCLOSE));
    }

    free_ptr (&data);

    return 0;
}