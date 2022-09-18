#include "process_text.h"

char **get_text (FILE *input, text_t *const text)
{
        struct stat file = {};
        stat("input.txt", &file);
        size_t n_chars = 0;
        char *buf = (char*) calloc(file.st_size + 1, sizeof(char));
        if (!buf) {
                printf("Calloc returned NULL.\n");
                return nullptr;
        }


        assert(buf);

        n_chars = fread(buf, sizeof(char), file.st_size, input);

        for (size_t i = 0; i < n_chars; i++)
                if (buf[i] == '\n')
                        buf[i] = '\0';

        buf[n_chars] = '\n';
        text->buf = buf;
        size_t n_lines = file.st_size - n_chars;
        n_lines++;
        text->n_lines = n_lines;
        //printf("%s\n%ld %lld\n %lld", buf, file.st_size, n_chars, text->n_lines);
        // printf("%s\n\n\n ", text->buf);
        // printf("%s\n\n\n ", text->lines);
        // char **qwerty = divide_text(text);
        // printf("%s\n", *qwerty);
        return divide_text(text);
}

//typedef struct stack
//{
//        ...
// } stack_t;

//typedef int (*)(const void *, const void *) comp_t;

// qsort(char *elems, size_t size, comp_t comp);

// split_text _t - delete
char **divide_text (text_t *const text)
{
        char *buf = text->buf;
        assert(buf);

        char **lines = (char**) calloc(text->n_lines + 1, sizeof(char*));
        if (!lines) {
                printf("Calloc returned NULL.\n");
                return nullptr;
        }
        // check

        text->lines = lines;
        lines[text->n_lines] = nullptr;
        for (size_t i = 0; i < text->n_lines; i++) {
                lines[i] = buf;
                while (*buf != '\n' && *buf != '\0')
                        buf++;
                buf++;
        }

        assert(*lines);

        //printf("%s\n\n\n ", *lines);
        return lines;
}
