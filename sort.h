#ifndef SORT_H
#define SORT_H

#include "main.h"

void bubble_sort_lines (text_t *text);
void swap_lines (char **lines, size_t i, size_t j);
void qsort_lines (char **lines, size_t left, size_t right);
int my_strcmp (const char *lhs, const char *rhs);

#endif /* SORT_H */
