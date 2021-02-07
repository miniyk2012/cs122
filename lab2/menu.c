#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

void triangle();
void rectangle();
void randomnumber();
void newline();
void randomchar();
void line();
void isleep();

int main() {
    char cmd[128];	
    while(1)
    {	
		scanf("%s", cmd);
        if(strcmp(cmd, "help") == 0) {
			printf("supported cmd:\nquit triangle rectangle randomnumber newline randomchar line sleep\n");
		}
        else if (strcmp(cmd, "rectangle") == 0) {
            rectangle();
        }
        else if (strcmp(cmd, "sleep") == 0) {
            isleep();
        }
        else if (strcmp(cmd, "randomchar") == 0) {
            randomchar();
        }
		else if (strcmp(cmd, "quit") == 0) {
			exit(0);				
		}
        else if (strcmp(cmd, "randomnumber") == 0) {
            randomnumber();
        } 
        else if (strcmp(cmd, "triangle") == 0) {
            triangle();
        }
        else if (strcmp(cmd, "newline") == 0) {
            newline();
        }
        else if (strcmp(cmd, "line") == 0) {
            line();
        }
		else {
			printf("this is wrong cmd\n");
        } 
    }
}
void triangle() {
    int n = 5;
    for(int i=0; i<n; i++) {
        int space = n - 1 - i;
        printf("%*s",space,"");
        for(int j=0;j<2*i-1;j++) {
            printf("*");
        }
        printf("\n");
    }
}

void rectangle() {
    int row = 5;
    int col = 4;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void randomnumber() {
    int m = 100;
    int n = rand()%m;
    printf("%d\n", n);
}

void newline() {
    printf("\n\n");
}

void randomchar() {
    char alpabet[26] = "abcdefghijklmnopqrstuvwxyz";
    int m = 26;
    int index = rand()%m;
    printf("%c\n", alpabet[index]);
}

void line() {
    int n = 50;
    for(int i=0; i<n; i++) {
        printf("_");
    }
    printf("\n");
}

void isleep() {
    printf("sleep");
    fflush(stdout);
    for(int i=0; i<3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("awake!\n");
}
