#ifndef ONEGIN_INPUT_PRINT_H
#define ONEGIN_INPUT_PRINT_H

char* onegin_input (FILE *stream, const size_t size_file);

void onegin_print (const char** data, const size_t n_lines, FILE *stream);

#endif //ONEGIN_INPUT_PRINT_H