/*单链表（有头节点）实现*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*函数定义*/
bool InitList(LinkedList *pList)
{
    Node *head;

    head = (Node *)malloc(sizeof(Node));
    if (!head)
        return false;
    *pList = head;
    (*pList)->next = NULL;

    return true;
}

bool ListIsNull(LinkedList *pList)
{
    if (*pList == NULL || (*pList)->next == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(LinkedList *pList)
{
    Node *pNewNode;

    pNewNode = (Node *)malloc(sizeof(Node));
    if (pNewNode == NULL)
        return true;

    return false;
}

unsigned int ListLength(LinkedList *pList)
{
    unsigned int count = 0;
    Node *pNode = (*pList)->next;

    if (ListIsNull(pList))
        return count;
    else
        while (pNode != NULL)
        {
            count++;
            pNode = pNode->next;
        }

    return count;
}

bool AddNode(LinkedList *pList, Data data)
{
    Node *pNewNode, *pNode;
    pNode = (*pList)->next;

    if (ListIsFull(pList))
    {
        fprintf(stderr, "Linked list is full.\n");
        return false;
    }

    pNewNode = (Node *)malloc(sizeof(Node));
    if (pNewNode == NULL)
    {
        fprintf(stderr, "Error in allocating space.\n");
        return false;
    }
    CopyDataToNode(pNewNode, data); //拷贝数据

    if (ListIsNull(pList))
        (*pList)->next = pNewNode;
    else
    {
        while (pNode->next != NULL)
            pNode = pNode->next;
        pNode->next = pNewNode;
    }

    return true;
}

void CopyDataToNode(Node *pNode, Data data)
{
    pNode->data = data;
    pNode->next = NULL;
}

bool DeleteNode(LinkedList *pList, int num)
{
    Node *pNode, *delNode;

    pNode = (*pList)->next;
    if (ListIsNull(pList) || num > ListLength(pList) || num < 1)
    {
        fprintf(stderr, "Linked list is full or error position.\n");
        return false;
    }

    for (int i = 1; i < num - 1; i++)
        pNode = pNode->next;
    delNode = pNode->next;
    pNode->next = delNode->next;
    free(delNode);

    return true;
}

bool GetNodeData(LinkedList *pList, int num, Node *pNode)
{
    Node *temp = (*pList)->next;

    if (ListIsNull(pList) || num > ListLength(pList) || num < 1)
    {
        fprintf(stderr, "Linked list is full or error position.\n");
        return false;
    }
    else
    {
        for (int i = 0; i < num - 1; i++)
            temp = temp->next;
        pNode->data = temp->data;
        pNode->next = temp->next;
    }

    return true;
}

bool InsertNode(LinkedList *pList, int num, Node *pNode)
{
    Node *pPrevNode = (*pList)->next, *pNewNode;

    if (ListIsNull(pList) || ListIsFull(pList) || num > ListLength(pList) + 1 || num < 1)
    {
        fprintf(stderr, "Linked list is full or invalid position.\n");
        return false;
    }

    pNewNode = (Node *)malloc(sizeof(Node));
    if (pNewNode == NULL)
    {
        fprintf(stderr, "Error in allocating space.\n");
        return false;
    }
    CopyDataToNode(pNewNode, pNode->data);
    pNewNode->next = NULL;

    for (int i = 1; i < num - 1; i++)
        pPrevNode = pPrevNode->next;
    pNewNode->next = pPrevNode->next;
    pPrevNode->next = pNewNode;

    return true;
}

void PrintNodeData(Node *pNode)
{
    printf("%d\n", pNode->data);
}

bool DestoryList(LinkedList *pList)
{
    Node *pNode, *delNode;
    pNode = *pList;

    if (ListIsNull(pList))
    {
        fprintf(stderr, "Linked list is empty.\n");
        return false;
    }
    else
        while (pNode != NULL)
        {
            delNode = pNode;
            pNode = pNode->next;
            free(delNode);
        }

    return true;
}

void ListTraverse(LinkedList *pList, void (*pFun)(Node *pNode))
{
    Node *pNode = (*pList)->next;

    while (pNode != NULL)
    {
        (*pFun)(pNode);
        pNode = pNode->next;
    }
}