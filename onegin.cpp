#include <stdio.h>
#include <stdlib.h>

#include "onegin_input_print.h"
#include "onegin_function.h"
#include "error.h"

int main ()
{
    FILE *fp_input = fopen ("onegin_input.txt", "rb");
    FILE *fp_print = fopen ("onegin_print.txt", "r+");

    if (fp_input == NULL || fp_print == NULL)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FOPEN));
    } 

    size_t size_file = get_file_size (fp_input);

    char *buf = (char *) onegin_input (fp_input, size_file);

    size_t n_lines =  number_of_lines (buf, size_file);

    char **text = split_lines (buf, size_file);

    //Первый вид сортировки - сортирует в алфавитном порядке по первым буквам

    bubble_sort (text, n_lines, string_cmp);

    onegin_print ((const char **) text, n_lines, fp_print);

    //Второй вид сортировки - сортирует в алфавитном порядке, но по последним буквам

    bubble_sort (text, n_lines, string_cmp_reverse);

    onegin_print ((const char **) text, n_lines, fp_print);

    //Обычный вывод - без сортировки, дефолтный текст из файла

    size_t t = 0;

    for (size_t i = 0; i <= size_file; i++)
    {
        if (*buf++ == '\0')
        {
            fprintf (fp_print, "%s", buf - t - 1);
            t = 0;
        }
        else 
        {
            t++;
        }
    }

    free (buf);
    free (text);

    if (fclose (fp_input) != 0 || fclose (fp_print) != 0)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FCLOSE));
    }

    return 0;
}