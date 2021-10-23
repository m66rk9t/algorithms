/*队列的顺序存储实现*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

/*函数定义*/
bool InitQueue(SeqQueue *sq)
{
    //为队列分配存储空间
    sq->base = (QElem *)malloc(MAXQSIZE * sizeof(QElem));
    //分配失败，返回false，初始化失败
    if (sq->base == NULL)
        return false;
    //分配成功，设置队头队尾
    sq->head = sq->tail = 0;
    //设置队列大小
    sq->maxqsize = MAXQSIZE - 1;
    //初始化成功
    return true;
}

bool QueueIsEmpty(SeqQueue *sq)
{
    if (!QueueLength(sq))
        return true;
    else
        return false;
}

bool QueueIsFull(SeqQueue *sq)
{
    if (QueueLength(sq) == sq->maxqsize)
        return true;
    else
        return false;
}

int QueueLength(SeqQueue *sq)
{
    return (sq->tail - sq->head);
}

bool EnQueue(SeqQueue *sq, QElem *elem)
{
    if (QueueIsFull(sq))
        return false;

    sq->base[sq->tail] = *elem;
    sq->tail += 1;

    return true;
}

bool DeQueue(SeqQueue *sq, QElem *elem)
{
    if (QueueIsEmpty(sq))
        return false;

    *elem = sq->base[sq->head];
    sq->head += 1;

    return true;
}

void PrintQElem(QElem *elem)
{
    printf("%d\n", *elem);
}

void QueueTraverse(SeqQueue *sq, void (*pFun)(QElem *))
{
    for (int i = 0; i < QueueLength(sq); i++)
    {
        pFun(&(sq->base[i]));
    }
}