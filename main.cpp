#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys\stat.h>

char **get_text(FILE *text);
char **devide_text(char *buf, int n_lines);
void free_ptrs(char **lines);

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

        printf("%s\n\n", lines[0]);

        free_ptrs(lines);

        fclose(text);
        fclose(output);
}

char **get_text(FILE *text)
{
        struct stat file;
        stat("input.txt", &file);
        int n_chars = 0;

        char *buf = (char*) calloc(sizeof(file.st_size) + 1, sizeof(char));
        n_chars = fread(buf, sizeof(char), file.st_size, text);

        buf[n_chars] = '\0';
        int n_lines = (file.st_size / sizeof(char)) - n_chars;

        return devide_text(buf, n_lines);
}

char **devide_text(char *buf, int n_lines)
{
        assert(buf);

        char **lines = (char**) calloc(n_lines + 1, sizeof(char*));

        for (int i = 0; i < n_lines; i++)
        {
                lines[i] = buf;
                while (*buf != '\n')
                        buf++;
        }

        assert(*lines);

        return lines;
}

void free_ptrs(char **lines)
{
        free(lines[0]);
        free(lines);
}

