#ifndef MAIN_H
#define MAIN_H

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

enum errors
{
        EMP_INPUT = 1,
        EMP_OUTPUT = 2
};

struct text_t
{
        size_t n_lines = 0;
        char **lines = nullptr;
        char *buf = nullptr;
};

void free_ptrs (char **lines, char *buf);
int err_print (int num);

void print_buf (const char **lines);

#endif /*MAIN_H*/
