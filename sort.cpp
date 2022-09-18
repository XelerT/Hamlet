#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "sort.h"

// int (*comp)(const void *, const void *)
int my_strcmp (const char *lhs, const char *rhs)
{
        assert(lhs);
        assert(rhs);

        while (!isalpha((int) *lhs) && *lhs != '\n')
                *lhs++;
        while (!isalpha((int) *rhs) && *rhs != '\n')
                *rhs++;

        while (*(lhs - 1))
                if (*lhs++ != *rhs++ && *lhs != '\n')
                        return  (*--lhs - *--rhs);

        return 0;
}


//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );
void bubble_sort_lines (char **lines)
{
        assert(lines);
        assert(*lines);

        for (int i = 0; lines[i] != nullptr; i++)
                for (int j = i + 1; lines[j] != nullptr; j++)
                        if (my_strcmp(lines[i], lines[j]) > 0)
                                swap_lines(lines, i, j);
}


//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );
void q_sort_lines (text_t *text, size_t left, size_t right)
{
        size_t i = 0;
        size_t last = 0;
        char **lines = text->lines;

        assert(lines);

        if (left >= right)
                return;
        swap_lines(lines, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
                if (my_strcmp(lines[i], lines[left]) < 0)
                        swap_lines(lines, i, ++last);

        swap_lines(lines, left, last);
        q_sort_lines(text, left, last - 1);
        q_sort_lines(text, last + 1, right);
}


// swap_ptrs (char **line1, char **line2)
void swap_lines (char **lines, size_t i, size_t j)
{
        assert(lines);

        char *swap = lines[i];
        lines[i] = lines[j];
        lines[j] = swap;
}
