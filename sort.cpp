#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "sort.h"

// int (*comp)(const void *, const void *)
int my_strcmp (const char *lhs, const char *rhs)
{
        assert(lhs);
        assert(rhs);

        printf("COMPARE!!! \n");

        while (!isalpha((int) *lhs) && *lhs != '\0')
                lhs++;
        while (!isalpha((int) *rhs) && *rhs != '\0')
                rhs++;

        while (*lhs)
                if (*lhs++ != *rhs++ || *lhs || *rhs)
                        return  *--lhs - *--rhs;

        return 0;
}


//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );

int comp (const void *lhs, const void *rhs)
{
        assert(lhs);
        assert(rhs);

        const char* lhs1 = *(const char**) lhs;
        const char* rhs1 = *(const char**) rhs;

        while (!isalpha((int) *lhs1) && *lhs1 != '\0')
                lhs1++;
        while (!isalpha((int) *rhs1) && *rhs1 != '\0')
                rhs1++;

        while (*lhs1)
                if (*lhs1++ != *rhs1++ || *lhs1 || *rhs1)
                        return  *--lhs1 - *--rhs1;

        return 0;
}

void bubble_sort_lines (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *))
{
        assert(ptr);

        lines_st *lines = (lines_st *) ptr;

        for (size_t i = 0; i < count; i++)
                for (size_t j = i + 1; j < count; j++)
                        if (comp((const char*) &((lines + i * size)->line),  (const char*) &((lines + j * size)->line)) > 0)
                                swap_lines(lines, i, j);
}

void rev_bsort_lines (void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *))
{
        assert(ptr);

        lines_st *lines = (lines_st *) ptr;
        char *line1 = "ABC";
        char *line2 = "CBA";
        printf("%d\n", rev_comp(line1 + 2, line2 + 2));

        for (size_t i = 1; i < count; i++)
                for (size_t j = i + 1; j < count; j++){
                        printf("%s\n", ((lines + (i * size))->line) + (lines + (i * size))->length - 1);
                        if (rev_comp((const char*) (&((lines + i * size)->line) + (lines + i * size)->length),  (const char*) (&((lines + j * size)->line) + (lines + j * size)->length)) > 0)
                        // (const char*) (&((lines + (i * size))->line) + (lines + (i * size))->length),  (const char*)( &((lines + j * size)->line) + (lines + (j * size))->length)
                                swap_lines(lines, i, j);
                }
}

int rev_comp (const void *lhs, const void *rhs)
{
        assert(lhs);
        assert(rhs);

        const char* lhs1 = *(const char**) lhs;
        const char* rhs1 = *(const char**) rhs;
        printf("WOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOW\n%s\n%s\n", lhs1, rhs1);

        while (!isalpha((int) *lhs1) && *lhs1 != '\0')
                lhs1--;
        while (!isalpha((int) *rhs1) && *rhs1 != '\0')
                rhs1--;
        printf("WOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOW\n%c\n%s\n", *lhs1, rhs1);
        while (*lhs1){
        printf("WOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOW\n%s\n%s\n", lhs1, rhs1);
                if (*lhs1-- != *rhs1-- || *lhs1 || *rhs1)
                      return  *++lhs1 - *++rhs1;
        }
        printf("WOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOWOW");

        return 0;
}

//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );
// void qsort_lines (char **lines, size_t left, size_t right)
// {
//         size_t i = 0;
//         size_t last = 0;
//
//         if (left >= right)
//                 return;
//         swap_lines(lines, left, (left + right) / 2);
//         last = left;
//         for (i = left + 1; i <= right; i++)
//                 if (my_strcmp(lines[i], lines[left]))
//                         swap_lines(lines, i, ++last);
//         swap_lines(lines, left, last);
//         qsort_lines(lines, left, last - 1);
//         qsort_lines(lines, last + 1, right);
// }

void swap_lines (lines_st *lines, size_t i, size_t j)
{
        assert(lines);
        lines_st swap = lines[i];
        lines[i] = lines[j];
        lines[j] = swap;
}
