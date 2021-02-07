#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void triangle();

int main() {
    char cmd[128];	
    while(1)
    {	
		scanf("%s", cmd);
        if(strcmp(cmd, "help") == 0) {
			printf("this is help cmd\n");
		}
		else if (strcmp(cmd, "quit") == 0) {
			exit(0);				
		}
        else if (strcmp(cmd, "triangle") == 0) {
            triangle();
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
