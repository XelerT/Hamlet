#ifndef PROCESS_TEXT_H
#define PROCESS_TEXT_H

#include <sys\stat.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

void get_text (FILE *input, text_t *text);

void divide_text (text_t *text);

void write_text (const text_t *text, FILE *output);

#endif /*PROCESS_TEXT_H*/
