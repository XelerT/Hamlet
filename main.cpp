#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys\stat.h>
#include <math.h>

char **get_text (FILE *text);
char **divide_text (char *buf, int n_lines);
void free_ptrs (char **lines);
int my_strcmp (const char *lhs, const char *rhs);
void print_buf (const char **lines);
void bubble_sort_lines (char **lines);
int err_print (int num);
char** check_pp_calloc (char **ptr);
char* check_p_calloc (char *ptr);
void swap_lines (char **lines, int i, int j);
void q_sort_lines (char **lines, int left, int right);

int main ()
{
        FILE *text   = nullptr;
        FILE *output = nullptr;

        text   = fopen("input.txt",  "r");
        output = fopen("output.txt", "w");

        if (text == nullptr)
                return err_print(1);

        else if (output == nullptr)
                return err_print(2);

        char **lines = get_text(text);
        //q_sort_lines(lines, 0, );
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
        char *buf = check_p_calloc((char*) calloc(file.st_size + 1, sizeof(char)));
        assert(buf);
        n_chars = fread(buf, sizeof(char), file.st_size, text);

        buf[n_chars] = '\n';
        int n_lines = file.st_size - n_chars;
        n_lines++;

        return divide_text(buf, n_lines);
}

char **divide_text (char *buf, int n_lines)
{
        assert(buf);
        char **lines = check_pp_calloc((char**) calloc(n_lines + 1, sizeof(char*)));
        lines[n_lines] = nullptr;
        for (size_t i = 0; i < n_lines; i++) {
                lines[i] = buf;
                while (*buf != '\n' && *buf != '\0')
                        buf++;
                buf++;
        }

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

        for (int i = 0; lines[i] != nullptr; i++)
                for (int j = i + 1; lines[j] != nullptr; j++)
                        if (my_strcmp(lines[i], lines[j]) > 0)
                                swap_lines(lines, i, j);
}

void q_sort_lines (char **lines, int left, int right)
{
        int i = 0;
        int last = 0;

        if (left >= right)
                return;
        swap_lines(lines, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
                if (my_strcmp(lines[i], lines[left]) > 0)
                        swap_lines(lines, i, ++last);
        swap_lines(lines, left, last);
        q_sort_lines(lines, left, last - 1);
        q_sort_lines(lines, last + 1, right);
}

void swap_lines (char **lines, int i, int j)
{
        char *swap = nullptr;
        swap = lines[i];
        lines[i] = lines[j];
        lines[j] = swap;
}

void print_buf (const char **lines)
{
        assert(lines);
        assert(*lines);

        while (*lines != nullptr) {
                for (int i = 0; (*lines)[i] != '\n'; i++)
                        putchar((*lines)[i]);
                putchar('\n');
                *(lines++);
        }
}

int err_print (int num)
{
        switch (num) {
        case 1:
                printf("Input file pointer is empty.\n");
                break;
        case 2:
                printf("Output file pointer is empty.\n");
                break;
        }

        return num;
}

char** check_pp_calloc (char **ptr)
{
        if (!ptr) {
                printf("Calloc returned NULL.\n");
        }

        return ptr;
}

char* check_p_calloc (char *ptr)
{
        if (!ptr) {
                printf("Calloc returned NULL.\n");
        }

        return ptr;
}
