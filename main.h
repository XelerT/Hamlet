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

struct lines_st
{
        char *line = nullptr;
        size_t length = 0;
};

struct text_t
{
        size_t n_lines = 0;
        size_t n_chars = 0;
        // char **lines = nullptr;
        char *buf = nullptr;
        lines_st *lines = nullptr;

};

void free_ptrs (lines_st *lines, char *buf);
int err_print (int num);

void print_text (text_t *text);

#endif /*MAIN_H*/
