#include "sort.h"
#include "process_text.h"
#include "sort.h"

int main ()
{
        FILE *input   = nullptr;
        FILE *output = nullptr;

        input  = fopen("input.txt",  "r");
        output = fopen("output.txt", "w");

        text_t text = {
                .n_lines = 0,
                .n_chars = 0,
                .buf = nullptr,
                .lines = {}
        };

        if (input == nullptr)
                return err_print(EMP_INPUT);

        else if (output == nullptr)
                return err_print(EMP_OUTPUT);

        get_text(input, &text);
        rev_bsort_lines(text.lines, text.n_lines, sizeof(char), comp);
        assert(text.lines);
        //qsort_lines(text.lines, 0, text.n_lines - 1);
        /*
        // fwrite(*(const char**) lines,  )
        // write_text ((const char**) lines, output, 5564);
*/
        //print_text(&text);

        free_ptrs(text.lines, text.buf);

        fclose(input);
        fclose(output);
}

void free_ptrs (lines_st *lines, char *buf)
{
        assert(lines);

// check free
        free(buf);
        free(lines);
}

void print_text (text_t *text)
{
        lines_st *lines = text->lines;

        assert(lines);

        for (size_t i = 0; i < text->n_lines; i++) {
                printf("%s\n", lines[i].line);
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

// void write_text (const char **lines, FILE *output, int n_lines)
// {
//         for (int i = 0; i < n_lines; i++)
//                 fwrite(lines, output);
// }
