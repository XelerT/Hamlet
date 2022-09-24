#include "sort.h"
#include "process_text.h"

int main ()
{
        FILE *input   = nullptr;
        FILE *output = nullptr;

        input  = fopen("input.txt",  "r");

        text_t text = {
                .n_lines = 0,
                .n_chars = 0,
                .buf = nullptr,
                .lines = {}
        };

        if (input == nullptr)
                return err_print(EMP_INPUT);

        get_text(input, &text);
        assert(text.lines);
        bubble_sort(text.lines, text.n_lines, sizeof(line_t), comp_lines);
        output = fopen("output.txt", "w");
        if (output == nullptr)
                return err_print(EMP_OUTPUT);
        write_text(&text, output);
        fclose(output);

        qsort(text.lines, text.n_lines, sizeof(line_t), rev_comp_lines);
        output = fopen("output.txt", "a");
        if (output == nullptr)
                return err_print(EMP_OUTPUT);

        write_text(&text, output);
        fputs(text.buf, output);

        free_ptrs(text.lines, text.buf);

        fclose(input);
        fclose(output);
}

void free_ptrs (line_t *lines, char *buf)
{
        assert(lines);

        free(buf);
        free(lines);
}

void print_text (text_t *text)
{
        line_t *lines = text->lines;

        assert(lines);

        for (size_t i = 0; i < text->n_lines; i++) {
                printf("%s\n", lines[i].ptr);
        }
}

int err_print (int num)
{
        switch (num) {
        case EMP_INPUT:
                printf("Input file pointer is empty.\n");
                break;
        case EMP_OUTPUT:
                printf("Output file pointer is empty.\n");
                break;
        default:
                printf("Unknown error.\n");
                break;
        }

        return num;
}
