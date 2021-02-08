#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1000 /* 每个输入行的最大长度 */

#if 0
int main(void) {
    char input[MAX_INPUT];
    int row = 0;
    while (gets(input) != NULL) {
        row += 1;
        printf("%d %s\n", row, input);
    }
}
#endif

int main(void)
{
    int ch;
    int line = 0;
    int at_beginning = 1;
    /* 键盘输入的字符都存到缓冲区内,一旦键入回车,getchar就进入缓冲区读取字符,
    ** 一次只返回第一个字符作为getchar函数的值,如果有循环或足够多的getchar语句,就会依次读出缓冲区内的所有字符
    */
    while((ch = getchar()) != EOF){
        if(at_beginning == 1){
            at_beginning = 0;
            line += 1;
            printf("%d ", line);
        }
        putchar(ch);
        if(ch == '\n')
            at_beginning = 1;
    }
    return EXIT_SUCCESS;
}