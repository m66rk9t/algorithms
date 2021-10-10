/*链式栈测试*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
char *s_gets(char *str, int n);

int main(void)
{
    LinkedStack ls; //声明一个链式栈
    Node *pNewNode; //声明临时节点

    InitStack(&ls);                          //初始化链式栈
    pNewNode = (Node *)malloc(sizeof(Node)); //为临时节点分配内存空间

    /*获取输入数据*/
    printf("Please enter student's ID, enter -1 to quit:");
    while (scanf("%d", &pNewNode->id) == 1 && pNewNode->id != -1)
    {
        pNewNode->next = NULL;
        Push(&ls, pNewNode);
        printf("Please enter the next ID:");
    }

    StackTraverse(&ls, PrintNodeData); //打印链式栈中各节点数据
    DestoryStack(&ls);                 //销毁栈，设为空栈
    free(pNewNode);                    //释放临时节点的空间
    puts("Done!");

    return 0;
}

char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}