#include <stdio.h>


int Max(int, int);

int main(void) {
    int (*p)(int,int);
    p = Max;
    int a, b;
    printf("please input a, b\n");
    scanf("%d%d", &a, &b);
    int c = p(a, b);
    printf("max of %d and %d is %d", a, b, c);
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}