/*使用单链表（有头节点）*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main(void)
{
    LinkedList List;
    Data input;
    unsigned int count = 0;

    /*初始化链表*/
    InitList(&List);

    /*获取输入,建立链表*/
    printf("Please enter student ID.\
    \nFor example: 3041. Enter -1 to quit:");
    while (scanf("%d", &input) == 1 && input != -1)
    {
        AddNode(&List, input);
        printf("Please enter the next ID:");
    }

    /*打印链表节点中的数据*/
    printf("Students' ID:\n");
    ListTraverse(&List, PrintNodeData);

    /*销毁表*/
    if (DestoryList(&List))
        printf("\nLinked list successfully destoryed!\n");
    puts("Done!");

    return 0;
}