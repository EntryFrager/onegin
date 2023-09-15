#ifndef INPUT_PRINT_H
#define INPUT_PRINT_H

#include "function.h"
#include "error.h"

int input_text (TEXT *data);

void print_sort_text (TEXT *data);

void print_text (TEXT *data);

size_t get_file_size (FILE *stream);

#endif //INPUT_PRINT_H