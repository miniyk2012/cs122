#include <stdio.h>
typedef struct _GPIO_t
{
    int in;
    int out;
    int type;
    int value;
} GPIO_t;
void printGPIO_t(GPIO_t *);

typedef struct _GPIO_m
{
    char in;
    char out;
    char type;
    char value;
    int data;
} GPIO_m;

int main(void)
{
    int a[] = {1, 2, 'a', 'b'};

    // 通过该方法可以把某一起始地址的数据类型与结构体成员相对应，以后直接通过结构体成员去访问
    GPIO_t *GPIOA = (GPIO_t *)a;
    printGPIO_t(GPIOA);
    GPIO_t GPIOB = {
        .in = 3,
        .out = 4,
        .type = 'A',
        .value = 'B'};
    printf("\n");
    printGPIO_t(&GPIOB);
    int b[] = {'abcd', 4444};
    GPIO_m *GPIOC = (GPIO_m *)b;
    printf("\n");
    printf("%c \n",GPIOC->in);
	printf("%c \n",GPIOC->out);
	printf("%c \n",GPIOC->type);
	printf("%c \n",GPIOC->value);
	printf("%d \n",GPIOC->data);
}

void printGPIO_t(GPIO_t *GPIOA)
{
    printf("%d\n", GPIOA->in);
    printf("%d\n", GPIOA->out);
    printf("%c\n", GPIOA->type);
    printf("%c\n", GPIOA->value);
}