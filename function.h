#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {
    size_t size_str = 0;
    char *str = NULL;
} LINE;

typedef struct {
    char file_name_input[17] = "onegin_input.txt";
    char file_name_print[17] = "onegin_print.txt";

    FILE *fp_input = NULL;
    FILE *fp_print = NULL;

    char *buf = NULL;
    char **text = NULL;

    size_t size_file = 0;
    size_t n_lines = 0;

    LINE *lines = NULL;
} TEXT;



void split_lines (TEXT *data);

char** bubble_sort (TEXT *data, int (*compare_func) (const void *str_1, const void *str_2));

//void my_qsort (void *text, size_t n_lines, size_t size_elements, int (*compare_func) (const void *str_1, const void *str_2));

int string_cmp (const void* s1, const void* s2);

int string_cmp_reverse (const void* s1, const void* s2);

void free_ptr (TEXT *data);

#endif //FUNCTION_H