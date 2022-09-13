#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys\stat.h>

char **get_text(FILE *text);
char **devide_text(char *buf, int n_lines);

int main ()
{
        FILE *text  = nullptr;
        FILE *output = nullptr;

        text   = fopen("input.txt",  "r");
        output = fopen("output.txt", "w");

        if (text == nullptr || output == nullptr)
                return 1;

        char **lines = get_text(text);

        printf("%s\n\n", lines[0]);

        fclose(text);
        fclose(output);
}

char **get_text(FILE *text)
{
        struct stat buffer;
        stat("input.txt", &buffer);
        int n_chars = 0;

        char *buf = (char*) calloc((sizeof(buffer.st_size) / sizeof(char)) + 1, sizeof(char));
        n_chars = fread(buf, sizeof(char), buffer.st_size / sizeof(char), text);

        buf[n_chars] = '\0';

        int n_lines = (buffer.st_size / sizeof(char)) - n_chars;

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
