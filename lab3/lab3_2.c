#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define CMD_MAX_LEN 128

typedef struct DataNode
{
    char *cmd;
    char *description;
    void (*handler)();
    struct DataNode *next;
} TDataNode;

void help();
void rectangle();
void triangle();
void randomnumber();
void newline();
void randomchar();
void line();
void isleep();
void quit();
TDataNode *findCmd(TDataNode *head, char *cmd);
int showAllCmd(TDataNode *head);


TDataNode head[] = {
    {"help", "show all cmds", help, &head[1]},
    {"rectangle", "draw rectangle", rectangle, &head[2]},
    {"triangle", "draw triangle", triangle, &head[3]},
    {"randomnumber", "produce a number", randomnumber, &head[4]},
    {"newline", "a new line", newline, &head[5]},
    {"randomchar", "produce a char", randomchar, &head[6]},
    {"line", "draw a line", line, &head[7]},
    {"sleep", "sleep three seconds", isleep, &head[8]},
    {"quit", "quit!", quit, NULL},
};

int main()
{
    char cmd[CMD_MAX_LEN];
    TDataNode *p;
    while (1)
    {
        scanf("%s", cmd);
        p = findCmd(head, cmd);
        if (p != NULL)
        {
            printf("%s - %s\n", cmd, p->description);
            if (p->handler != NULL)
            {
                p->handler();
            }
        }
        else
        {
            printf("this is a wrong cmd.\n");
        }
    }
}

TDataNode *findCmd(TDataNode *head, char *cmd)
{
    if (head == NULL || cmd == NULL) {
        return NULL;
    }
    TDataNode *p = head;
    while (p != NULL)
    {
        if (strcmp(p->cmd, cmd) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int showAllCmd(TDataNode *head) {
    printf("Menu List:\n");
    TDataNode *p = head;
    while (p!=NULL) {
        printf("%s - %s\n", p->cmd, p->description);
        p = p->next;
    }
    return 0;
}

void help()
{
    showAllCmd(head);
}

void triangle()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int space = n - 1 - i;
        printf("%*s", space, "");
        for (int j = 0; j < 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void rectangle()
{
    int row = 5;
    int col = 4;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void randomnumber()
{
    int m = 100;
    int n = rand() % m;
    printf("%d\n", n);
}

void newline()
{
    printf("\n");
}

void randomchar()
{
    char alpabet[26] = "abcdefghijklmnopqrstuvwxyz";
    int m = 26;
    int index = rand() % m;
    printf("%c\n", alpabet[index]);
}

void line()
{
    int n = 50;
    for (int i = 0; i < n; i++)
    {
        printf("_");
    }
    printf("\n");
}

void isleep()
{
    printf("sleep");
    fflush(stdout);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("awake!\n");
}

void quit()
{
    exit(EXIT_SUCCESS);
}