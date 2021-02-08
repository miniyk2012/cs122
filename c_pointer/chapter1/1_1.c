#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COLS 20    /* 所能处理的最大列号 */
#define MAX_INPUT 1000 /* 每个输入行的最大长度 */

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);
    printf("n_columns = %d\n", n_columns);

    while (gets(input) != NULL)
    {
        printf("Original input : %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;

    if (num % 2 != 0)
    {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    while ((ch = getchar()) != EOF && ch != '\n')
        ;

    return num;
}

void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for (col = 0; col < n_columns; col += 2)
    {
        int nchars = columns[col + 1] - columns[col] + 1;
        /*
        ** 如果输入行结束或输出行数组已满, 就结束任务.
        */
        if (columns[col] >= len || output_col == MAX_INPUT + 1) {
            break;
        }
        /*
        ** 如果输出行数据空间不够, 只复制可以容纳的数据
        */
       if (output_col + nchars > MAX_INPUT -1) {
           nchars = MAX_INPUT - output_col - 1;
       }

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';

}
