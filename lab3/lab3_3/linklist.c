#include <stdio.h>
#include <string.h>
#include "linklist.h"


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