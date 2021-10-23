/*链式队列实现*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

/*函数定义*/
bool InitQueue(LinkedQueue *lq)
{
    if (QueueStatus)
        Error(QueueStatus);

    lq->head = (QueueNode *)malloc(sizeof(QueueNode));

    if (!lq->head)
        return false;

    lq->head->next = NULL;
    lq->tail = lq->head;
    QueueStatus = 1;

    return true;
}

bool DestoryQueue(LinkedQueue *lq)
{
    QueueNode *freeNode, *nextNode;

    if (!QueueStatus)
        Error(QueueStatus);

    freeNode = lq->head;

    while (freeNode)
    {   
        nextNode = freeNode->next;
        free(freeNode);
        freeNode = nextNode;
    }
}

bool QueueIsEmpty(LinkedQueue *lq)
{
    if (!QueueStatus)
        Error(QueueStatus);

    if (lq->head == lq->tail)
        return true;
    else
        return false;
}

bool QueueIsFull(LinkedQueue *lq)
{
    QueueNode *newNode;

    if (!QueueStatus)
        Error(QueueStatus);

    newNode = (QueueNode *)malloc(sizeof(QueueNode));

    if (!newNode)
        return true;
    else
        return false;
}

bool ClearQueue(LinkedQueue *lq)
{
    QueueNode *freeNode, *nextNode;

    if (!QueueStatus)
        Error(QueueStatus);

    freeNode = lq->head->next;
    nextNode = freeNode->next;
    lq->tail = lq->head;
    lq->head->next = NULL;

    while (nextNode)
    {
        free(freeNode);
        freeNode = nextNode;
        nextNode = nextNode->next;
    }
}

unsigned int QueueLength(LinkedQueue *lq)
{
    unsigned int length = 0U;
    QueueNode *pNode = lq->head->next;

    while (pNode)
    {
        length++;
        pNode = pNode->next;
    }

    return length;
}

bool EnQueue(LinkedQueue *lq, QueueNode *node)
{
    QueueNode *pNode;

    if (!QueueStatus)
        Error(QueueStatus);

    if (QueueIsFull(lq))
        return false;
    // puts("EN");
    pNode = (QueueNode *)malloc(sizeof(QueueNode));

    if (!pNode)
        return false;

    CopyNodeData(pNode, node);
    pNode->next = NULL;

    if (QueueIsEmpty(lq))
        lq->head->next = pNode;
    else
        lq->tail->next = pNode;
    lq->tail = pNode;
}

bool DeQueue(LinkedQueue *lq, QueueNode *node)
{
    QueueNode *freeNode;

    if (!QueueStatus)
        Error(QueueStatus);

    if (QueueIsEmpty(lq))
        return false;

    CopyNodeData(node, lq->head->next);

    freeNode = lq->head->next;
    lq->head->next = freeNode->next;
    if (lq->tail == freeNode)
        lq->tail = lq->head;
    free(freeNode);

    return true;
}

bool GetHead(LinkedQueue *lq, QueueNode *node)
{
    CopyNodeData(node, lq->head->next);
}

void PrintQNodeData(QueueNode *node)
{
    printf("%d\n", node->data);
}

void QueueTraverse(LinkedQueue *lq, void (*pFun)(QueueNode *))
{
    QueueNode *pNode = lq->head->next;

    if (!QueueStatus)
        Error(QueueStatus);

    while (pNode)
    {
        pFun(pNode);
        pNode = pNode->next;
    }
}

void CopyNodeData(QueueNode *tar, QueueNode *src)
{
    tar->data = src->data;
}

void Error(int statuscode)
{
    switch (statuscode)
    {
    case 0:
        fprintf(stderr, "The queue was not initialized.\n");
        exit(EXIT_FAILURE);
        break;
    case 1:
        fprintf(stderr, "The queue has been initialized.\n");
        exit(EXIT_FAILURE);
        break;
    default:
        break;
    }
}