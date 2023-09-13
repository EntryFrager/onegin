#ifndef ONEGIN_FUNCTION_H
#define ONEGIN_FUNCTION_H

size_t get_file_size (FILE *stream);

size_t number_of_lines (const char *data, const size_t size);

char** split_lines (char *data, const size_t size);

char** bubble_sort (char** data, const size_t n_lines, int (*compare_func) (const void *str_1, const void *str_2));

int string_cmp (const void* s1, const void* s2);

int string_cmp_reverse (const void* s1, const void* s2);

#endif //ONEGIN_FUNCTION_H