#include "sort.h"
#include "process_text.h"

int main ()
{
        FILE *input   = nullptr;
        FILE *output = nullptr;

        input   = fopen("input.txt",  "r");
        output = fopen("output.txt", "w");

        text_t text = {
                .n_lines = 0,
                .lines = nullptr,
                .buf = nullptr
        };

        if (input == nullptr)
                return err_print(EMP_INPUT);

        else if (output == nullptr)
                return err_print(EMP_OUTPUT);

        get_text(input, &text);
        printf("HEREQWERTY %d\n\n", __LINE__);

        // printf("%s\n\n\n ", text->buf);

// \r\n --> \0
//[text \0 ... .\0. . .. . . . \0. .]
//^       ^         ^
//|       |         |
//[p1     p2        p3 p4 p5]
        //bubble_sort_lines(lines);
        assert(text.lines);
        //printf("%s\n\n\n", *text.lines);
        printf("%s\n\n\n %d\n%s\n", *text.lines, text.n_lines - 1, text.buf);


        q_sort_lines(&text, 0, text.n_lines - 1);/*


        printf("HERER\n, %d", __LINE__);
        print_buf((const char**) text.lines);

        // fwrite(*(const char**) lines,  )
        // write_text ((const char**) lines, output, 5564);
*/
        printf("%s\n\n\n %d", *text.lines, text.n_lines - 1);
        free_ptrs(text.lines, text.buf);

        fclose(input);
        fclose(output);
}

void free_ptrs (char **lines, char *buf)
{
        assert(lines);
        assert(*lines);

// check free
        free(buf);
        free(lines);
}

void print_buf (const char **lines)
{
        assert(lines);
        assert(*lines);
        printf("HERE %d\n\n", __LINE__);
        while (*lines != nullptr) {
                for (int i = 0; (*lines)[i] != '\n'; i++)
                        putchar((*lines)[i]);
                putchar('\n');
                lines++;
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
