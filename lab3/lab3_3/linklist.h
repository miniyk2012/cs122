/*
** data struct and its operations
*/
typedef struct DataNode
{
    char *cmd;
    char *description;
    void (*handler)();
    struct DataNode *next;
} TDataNode;

TDataNode *findCmd(TDataNode *head, char *cmd);
int showAllCmd(TDataNode *head);