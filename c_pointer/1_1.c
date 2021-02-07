#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COLS 20

int read_column_numbers(int columns[], int max);

int main() {
	int n_columns;
	int columns[MAX_COLS];

	n_columns = read_column_numbers(columns, MAX_COLS);
	printf("n_columns = %d", n_columns);
	
}


int read_column_numbers(int columns[], int max) {
    int num = 0;
    int ch;

    while(num<max && scanf("%d", &columns[num]) == 1 && columns[num] >=0 )
        num += 1;

    if (num % 2 != 0) {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    while ((ch=getchar()) != EOF && ch!='\n') {
        printf("%d\n", ch);
    }

    return num;
}

