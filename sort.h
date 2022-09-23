#ifndef SORT_H
#define SORT_H

#include "main.h"

void swap(void *ptr1, void *ptr2, size_t size);

int comp_lines (const void *line1, const void *line2);
int rev_comp_lines (const void *line1, const void *line2);

void bubble_sort_lines (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));

#endif /* SORT_H */
