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

    lq->head = lq->tail = NULL;
    QueueStatus = 1;

    return true;
}

bool DestoryQueue(LinkedQueue *lq)
{
    QueueNode *nextNode;

    if (!QueueStatus)
        Error(QueueStatus);

    if (QueueIsEmpty(lq))
        return false;

    while (lq->head != NULL)
    {
        nextNode = lq->head->next;
        free(lq->head);
        lq->head = nextNode;
    }

    return true;
}

bool QueueIsEmpty(LinkedQueue *lq)
{
    if (!QueueStatus)
        Error(QueueStatus);

    if (lq->head == NULL && lq->tail == NULL)
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

unsigned int QueueLength(LinkedQueue *lq)
{
    unsigned int length = 0U;
    QueueNode *pNode = lq->head;

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
        lq->head = lq->tail = pNode;
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

    CopyNodeData(node, lq->head);

    freeNode = lq->head;
    lq->head = freeNode->next;
    if (lq->tail == freeNode)
        lq->tail = lq->head;
    free(freeNode);

    return true;
}

bool GetHead(LinkedQueue *lq, QueueNode *node)
{
    CopyNodeData(node, lq->head);
}

void PrintQNodeData(QueueNode *node)
{
    printf("%d\n", node->data);
}

void QueueTraverse(LinkedQueue *lq, void (*pFun)(QueueNode *))
{
    QueueNode *pNode = lq->head;

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