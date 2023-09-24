#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {
    size_t size_str = 0;
    char *str = NULL;
} LINE;

typedef struct {
    const char *file_name_input = NULL;
    const char *file_name_print = NULL;

    FILE *fp_input = NULL;
    FILE *fp_print = NULL;

    char *buf = NULL;

    size_t size_file = 0;
    size_t n_lines = 0;

    LINE *lines = NULL;
} TEXT;

void split_lines (TEXT *data);

char** bubble_sort (TEXT *data, int (*compare_func) (const void *str_1, const void *str_2));

void my_qsort (void *line_1, size_t first, size_t last, int (*compare_func) (const void *str_1, const void *str_2_));

int string_cmp (const void* s1, const void* s2);

int string_cmp_reverse (const void* s1, const void* s2);

void free_ptr (TEXT *data);

#endif //FUNCTION_H