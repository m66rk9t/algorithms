/*单链表（无头节点）实现*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*函数定义*/
void InitList(LinkedList *pList)
{
    *pList = NULL; //将单链表设置为空
}

bool ListIsNull(LinkedList *pList)
{
    if (*pList == NULL) //判断单链表是否为空
        return true;
    else
        return false;
}

bool ListIsFull(LinkedList *pList)
{
    Node *pNewNode;

    pNewNode = (Node *)malloc(sizeof(Node));
    //查看是否还有可用的内存分配给新的节点，没有的话说明内存已满，新节点内存分配失败，malloc()返回NULL
    if (pNewNode == NULL)
        return true;

    return false;
}

unsigned int ListLength(LinkedList *pList)
{
    unsigned int count = 0;
    Node *pNode = *pList;

    if (ListIsNull(pList)) //单链表为空，长度/节点数量为0
        return count;
    else
        while (pNode != NULL)
        {
            count++;
            pNode = pNode->next; //指向下一个节点
        }

    return count;
}

bool AddNode(LinkedList *pList, Data data)
{
    Node *pNewNode, *pNode;
    pNode = *pList; //指向单链表

    if (ListIsFull(pList)) //判断是否已满
    {
        fprintf(stderr, "Linked list is full.\n");
        return false;
    }

    pNewNode = (Node *)malloc(sizeof(Node));
    if (pNewNode == NULL) //判断是否成功分配存储空间
    {
        fprintf(stderr, "Error in allocating space.\n");
        return false;
    }
    CopyDataToNode(pNewNode, data); //拷贝数据

    if (ListIsNull(pList)) //单链表为空则将新节点设为第一节点
        *pList = pNewNode;
    else
    { /*寻找尾部节点并添加新节点*/
        while (pNode->next != NULL)
            pNode = pNode->next;
        pNode->next = pNewNode;
    }

    return true; //成功添加
}

void CopyDataToNode(Node *pNode, Data data)
{
    pNode->id = data;   //拷贝数据
    pNode->next = NULL; //将每个新节点都设为最后一个节点
}

bool DeleteNode(LinkedList *pList, int num)
{
    Node *pNode, *delNode;

    pNode = *pList;                                   //指向单链表
    if (ListIsNull(pList) || num > ListLength(pList)) //单链表是否为空或待删除的节点序号超出长度上限
    {
        fprintf(stderr, "Linked list is full or error position.\n");
        return false;
    }
    /*寻找待删除节点的上一个节点*/
    for (int i = 1; i < num - 1; i++)
        pNode = pNode->next;
    delNode = pNode->next;       //待删除节点
    pNode->next = delNode->next; //待删除节点的上一节点的next指针指向待删除节点的下一节点
    free(delNode);               //释放动态分配的存储空间

    return true; //删除节点成功
}

bool GetNodeData(LinkedList *pList, int num, Node *pNode)
{
    Node *temp = *pList; //指向单链表

    if (ListIsNull(pList) || num > ListLength(pList)) //单链表是否为空或指定的序号超出长度上限
    {
        fprintf(stderr, "Linked list is full or error position.\n");
        return false;
    }
    else
    {
        /*寻找待读取的节点*/
        for (int i = 0; i < num - 1; i++)
            temp = temp->next;
        pNode->id = temp->id;     //拷贝数据
        pNode->next = temp->next; //设置指针
    }

    return true; //成功读取
}

bool InsertNode(LinkedList *pList, int num, Node *pNode)
{
    Node *pPrevNode = *pList, *pNewNode;

    /*单链表是否为空或已满或指定的序号超出最大上限*/
    if (ListIsNull(pList) || ListIsFull(pList) || num > ListLength(pList) + 1)
    {
        fprintf(stderr, "Linked list is full or invalid position.\n");
        return false;
    }

    pNewNode = (Node *)malloc(sizeof(Node)); //为待插入的新节点分配新的储存空间
    if (pNewNode == NULL)                    //判断是否成功分配
    {
        fprintf(stderr, "Error in allocating space.\n");
        return false;
    }
    CopyDataToNode(pNewNode, pNode->id); //拷贝数据
    pNewNode->next = NULL;               //设置指针为NULL

    /*寻找待插入位置的上一节点并插入新的节点*/
    for (int i = 1; i < num - 1; i++)
        pPrevNode = pPrevNode->next;
    pNewNode->next = pPrevNode->next;
    pPrevNode->next = pNewNode;

    return true; //插入成功
}

void PrintNodeData(Node *pNode)
{
    printf("%d\n", pNode->id); //打印节点的数据
}

bool DestoryList(LinkedList *pList)
{
    Node *pNode, *delNode;
    pNode = *pList; //指向单链表

    if (ListIsNull(pList)) //判断单链表是否为空
    {
        fprintf(stderr, "Linked list is full.\n");
        return false;
    }
    else
        while (pNode != NULL) //按顺序一次释放节点的存储空间
        {
            delNode = pNode;     //获取待释放节点的地址
            pNode = pNode->next; //获取下一个待释放节点的地址
            free(delNode);       //释放
        }

    return true; //成功销毁链表
}

void Traverse(LinkedList *pList, void (*pFun)(Node *pNode))
{
    Node *pNode = *pList; //指向单链表

    while (pNode != NULL) //指向的节点不为NULL时
    {
        (*pFun)(pNode);      //pFun指向的函数作用于当前节点
        pNode = pNode->next; //获取下一个节点的地址
    }
}