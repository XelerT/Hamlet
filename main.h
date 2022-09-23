#ifndef MAIN_H
#define MAIN_H


#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

// io
enum errors
{
        EMP_INPUT  = 1,
        EMP_OUTPUT = 2
};


// text.h
// st --> t
struct line_t
{
        char *ptr = nullptr;
        size_t length = 0;
};

// text.h
struct text_t
{
        size_t n_lines = 0;
        size_t n_chars = 0;
        char *buf = nullptr;
        line_t *lines = nullptr;
};

// text
void free_ptrs (line_t *lines, char *buf);
int err_print (int num);

void print_text (text_t *text);

#endif /*MAIN_H*/
