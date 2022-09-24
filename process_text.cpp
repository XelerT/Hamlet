#include "process_text.h"

void get_text (FILE *input, text_t *text)
{
        struct stat file = {};
        if (stat("input.txt", &file) < 0)
                return;

        size_t n_chars = 0;
        char *buf = (char*) calloc(file.st_size + 1, sizeof(char));
        if (!buf) {
                printf("Calloc returned NULL.\n");
                return;
        }

        assert(buf);

        n_chars = fread(buf, sizeof(char), file.st_size, input);
        text->n_chars = n_chars;

        text->buf = buf;
        size_t n_lines = file.st_size - n_chars;

        text->n_lines = n_lines;
        divide_text(text);
}

void divide_text (text_t *text)
{
        char *buf = text->buf;
        assert(buf);

        buf[text->n_chars + 1] = '\0';

        struct line_t *lines = (struct line_t*) calloc(text->n_lines + 1, sizeof(line_t));
        if (!lines) {
                printf("Calloc returned NULL.\n");
                return;
        }
        text->lines = lines;
        for (size_t i = 0; i < text->n_lines; i++) {
                lines[i].ptr = buf;
                while (*buf != '\n' && *buf != '\0')
                        buf++;
                buf++;
                lines[i].length = buf - lines[i].ptr;
        }
        assert(lines);
}

void write_text (const text_t *text, FILE *output)
{
        assert(text);
        assert(output);

        for (size_t i = 0; i < text->n_lines; i++) {
                int j = 0;
                while (text->lines[i].ptr[j] != '\n') {
                        fputc(text->lines[i].ptr[j], output);
                        j++;
                }
                fputc('\n', output);
        }
}
