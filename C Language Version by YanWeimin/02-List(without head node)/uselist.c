/*使用单链表（无头节点）*/
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
    Traverse(&List, PrintNodeData);

    /*插入一个节点*/
    Node newNode;
    printf("Please enter new node's data:");
    scanf("%d", &newNode.id);
    newNode.next=NULL;
    InsertNode(&List, 2, &newNode);

    /*打印链表节点中的数据*/
    printf("Students' ID:\n");
    Traverse(&List, PrintNodeData);

    /*销毁表*/
    DestoryList(&List);

    return 0;
}