#ifndef PROCESS_TEXT_H
#define PROCESS_TEXT_H

#include <sys\stat.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

char **get_text (FILE *input, text_t *text);
char **divide_text (text_t *text);
// void write_text (const char **lines, FILE *output, int n_lines);

#endif /*PROCESS_TEXT_H*/
