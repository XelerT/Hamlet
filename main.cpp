#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys\stat.h>
#include <math.h>

char **get_text (FILE *text);
char **devide_text (char *buf, int n_lines);
void free_ptrs (char **lines);
int my_strcmp (const char *lhs, const char *rhs);
void print_buf (const char **lines);
void bubble_sort_lines (char **lines);

int main ()
{
        FILE *text  = nullptr;
        FILE *output = nullptr;

        text   = fopen("input.txt",  "r");
        output = fopen("output.txt", "w");

        if (text == nullptr)
                return 1;

        else if (output == nullptr)
                return 2;

        char **lines = get_text(text);

        //         printf("1\n");
        // print_buf((const char**) lines);
        bubble_sort_lines(lines);
                printf("2\n");
        print_buf((const char**) lines);

        free_ptrs(lines);

        fclose(text);
        fclose(output);
}

char **get_text (FILE *text)
{
        struct stat file;
        stat("input.txt", &file);
        int n_chars = 0;

        char *buf = (char*) calloc(sizeof(file.st_size) + 1, sizeof(char));
        n_chars = fread(buf, sizeof(char), file.st_size, text);

        buf[n_chars] = '\n';
        int n_lines = (file.st_size / sizeof(char)) - n_chars;

        return devide_text(buf, n_lines);
}

char **devide_text (char *buf, int n_lines)
{
        assert(buf);

        char **lines = (char**) calloc(n_lines + 1, sizeof(char*));
        lines[n_lines] = nullptr;
// printf("/%d\n", n_lines);
        for (int i = 0; i < n_lines; i++)
        {
                lines[i] = buf;
                // printf("%s\n", buf);
                while (*buf != '\n' && *buf != '\0')
                        buf++;
                buf++;
        }
// printf("\\\n");
        assert(*lines);

        return lines;
}

void free_ptrs (char **lines)
{
        assert(lines);
        assert(*lines);

        free(lines[0]);
        free(lines);
}

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
                        return  (*--lhs - *--rhs) / fabs(*lhs - *rhs);

        return 0;
}

void bubble_sort_lines (char **lines)
{
        assert(lines);
        assert(*lines);

        char *swap = nullptr;

        for (int i = 0; lines[i] != nullptr; i++)
                for (int j = i + 1; lines[j] != nullptr; j++)
                        if (my_strcmp(lines[i], lines[j]) > 0)
                        {
                                swap = lines[i];
                                lines[i] = lines[j];
                                lines[j] = swap;
                        }
}

void print_buf (const char **lines)
{
        assert(lines);
        assert(*lines);

        // printf("QWERTY\n%s\n\n", lines[0]);

        while (*lines != nullptr)
        {
                for (int i = 0; (*lines)[i] != '\n'; i++)
                        putchar((*lines)[i]);
                        // printf("%d\n", i);
                // printf(" %s\n", *lines);
                putchar('\n');
                *(lines++);
        }
        // printf("%s\n", *(--lines));
}

