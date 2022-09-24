#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "sort.h"

void bubble_sort (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *))
{
        assert(ptr);

        for (size_t i = 0; i < count; i++)
                for (size_t j = i + 1; j < count; j++)
                        if (comp(ptr + i * size, ptr + j * size) > 0)
                                swap(ptr + i * size, ptr + j * size, size);
}

int comp_lines (const void *line1, const void *line2)
{
        assert(line1);
        assert(line2);

        line_t *line_1 = (line_t *) line1;
        line_t *line_2 = (line_t *) line2;

        const char* lhs = line_1->ptr;
        const char* rhs = line_2->ptr;

        while (!isalpha((int) *lhs) && *lhs != '\0' && *lhs != '\n')
                lhs++;
        while (!isalpha((int) *rhs) && *rhs != '\0' && *rhs != '\n')
                rhs++;

        while (*lhs)
                if (*lhs++ != *rhs++ || *lhs == '\n')
                        return  *(--lhs) - *(--rhs);

        return 0;
}

int rev_comp_lines (const void *line1, const void *line2)
{
        assert(line1);
        assert(line2);

        line_t *line_1 = (line_t *) line1;
        line_t *line_2 = (line_t *) line2;

        const char* lhs = line_1->ptr + line_1->length - 2;
        const char* rhs = line_2->ptr + line_2->length - 2;

        while (!isalpha((int) *lhs) && *lhs != '\0' && *lhs != '\n')
                lhs--;
        while (!isalpha((int) *rhs) && *rhs != '\0' && *rhs != '\n')
                rhs--;

        while (*lhs)
                if (*lhs-- != *rhs-- || *lhs == '\n')
                        return  *(++lhs) - *(++rhs);

        return 0;
}

void swap (void* ptr1, void* ptr2, size_t size)
{
    void* tmp = calloc(1, size);
    memcpy(tmp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, tmp, size);
    free(tmp);
}
