/*链式栈实现*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

void InitStack(LinkedStack *pStack)
{
    if (!StackIsNull(pStack))
        DestoryStack(pStack);
    else
        pStack->base = pStack->top = NULL;
}

void DestoryStack(LinkedStack *pStack)
{
    Node * delNode, *pNextNode;
    delNode = pStack->top;

    while (delNode)
    {
        pNextNode = delNode->next;
        free(delNode);
        delNode = pNextNode;
    }
    pStack->base = pStack->top = NULL;
}

bool StackIsNull(LinkedStack *pStack)
{
    if (!pStack->base&&!pStack->top)
        return true;
    else
        return false;
}

bool StackIsFull(LinkedStack * pStack)
{
    Node * pNewNode;

    pNewNode = (Node *)malloc(sizeof(Node));

    if (pNewNode)
        return false;
    else
        return true;
}

unsigned int StackLength(LinkedStack *pStack)
{
    unsigned int ct_node = 0U;
    Node * pNode = pStack->top;

    while (pNode)
    {
        ct_node++;
        pNode = pNode->next;
    }

    return ct_node;
}

bool Push(LinkedStack *pStack, Node *pNode)
{
    Node * pNewNode;
    
    if (StackIsFull(pStack))
        return false;
    pNewNode = (Node *)malloc(sizeof(Node));
    if (!pNewNode)
        return false;
    CopyDataToNode(pNewNode, pNode);

    if (StackIsNull(pStack))
        pStack->base = pStack->top = pNewNode;
    else
    {
        pNewNode->next = pStack->top;
        pStack->top = pNewNode;
    }

    return true;
}

bool Pop(LinkedStack *pStack)
{
    Node * pDelNode;

    if (StackIsNull(pStack))
        return false;
    
    pDelNode = pStack->top;
    pStack->top = pStack->top->next;
    free(pDelNode);
    pDelNode = NULL;

    return false;
}

bool GetTop(LinkedStack *pStack, Node *pNode)
{
    if (StackIsNull(pStack))
        return false;
    
    CopyDataToNode(pNode, pStack->top);

    return true;
}

void CopyDataToNode(Node * tar, Node * src)
{
    tar->id = src->id;
    tar->next = src->next;
}
void PrintNodeData(Node *pNode)
{
    printf("ID:%d\n", pNode->id);
}

void StackTraverse(LinkedStack *pStack, void (*pFun)(Node *))
{
    Node * pNode = pStack->top;

    while (pNode)
    {
        (*pFun)(pNode);
        pNode=pNode->next;
    }
}