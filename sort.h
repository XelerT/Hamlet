#ifndef SORT_H
#define SORT_H

#include "main.h"

// void bubble_sort_lines (text_t *text);
void swap_lines (lines_st *lines, size_t i, size_t j);
void qsort_lines (char **lines, size_t left, size_t right);
int my_strcmp (const char *lhs, const char *rhs);

void swap_ptr (char *line1, char *line2);
void bubble_sort_lines (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
int comp (const void *lhs, const void *rhs);

void rev_bsort_lines (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
int rev_comp (const void *lhs, const void *rhs);


#endif /* SORT_H */
