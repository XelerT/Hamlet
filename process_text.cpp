#include "process_text.h"

void get_text (FILE *input, text_t *text)
{
        struct stat file = {};
        stat("input.txt", &file);
        size_t n_chars = 0;
        char *buf = (char*) calloc(file.st_size + 1, sizeof(char));
        if (!buf) {
                printf("Calloc returned NULL.\n");
                buf = nullptr;
        }

        assert(buf);

        n_chars = fread(buf + 1, sizeof(char), file.st_size, input);
        text->n_chars = n_chars;

        buf[n_chars] = '\0';
        for (size_t i = 1; i < n_chars; i++)
                if (buf[i] == '\n')
                        buf[i] = '\0';

        text->buf = buf;
        size_t n_lines = file.st_size - n_chars;
        n_lines++;
        text->n_lines = n_lines;
        divide_text(text);
}

void divide_text (text_t *text)
{
        char *buf = text->buf;
        assert(buf);
        struct lines_st *lines = (struct lines_st*) calloc(text->n_lines + 1, sizeof(lines_st));
        if (!lines) {
                printf("Calloc returned NULL.\n");
                lines = nullptr;
        }
        text->lines = lines;
        for (size_t i = 0; i < text->n_lines; i++) {
                lines[i].line = buf;
                while (*buf != '\n' && *buf != '\0')
                        buf++;
                buf++;
                lines[i].length = buf - lines[i].line;
        }
        assert(lines);
}

void write_text (text_t *text, FILE *output)
{
        char n[] = {'\n', '\0'};
        char *ptr1 = n;
        for (size_t i = 0; i < text->n_lines; i++){
                fputs(text->lines[i].line, output);
                fputs(ptr1, output);
        }
}

void write_buf (text_t *text, FILE *output)
{
        char *buf = text->buf;
        for (size_t i = 0; i < text->n_chars; i++)
                if (buf[i] == '\0')
                        buf[i] = '\n';
        fputs(text->buf, output);
}
