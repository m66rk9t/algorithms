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

void DestoryQueue(SeqQueue *sq)
{
    free(sq->base);
}

bool QueueIsEmpty(SeqQueue *sq)
{
    //队列长度不为0，队列不为空
    if (!QueueLength(sq))
        return true;
    else
        return false;
}

bool QueueIsFull(SeqQueue *sq)
{
    //队列长度未达到上限
    if (QueueLength(sq) == sq->maxqsize)
        return true;
    else
        return false;
}

int QueueLength(SeqQueue *sq)
{
    //返回队列长度
    return (sq->tail - sq->head);
}

bool EnQueue(SeqQueue *sq, QElem *elem)
{
    //队列已满，入队失败
    if (QueueIsFull(sq))
        return false;

    //入队，重置队尾指针
    sq->base[sq->tail] = *elem;
    sq->tail += 1;

    //入队成功
    return true;
}

bool DeQueue(SeqQueue *sq, QElem *elem)
{
    //队列为空，出队失败
    if (QueueIsEmpty(sq))
        return false;

    //出队，重置队头指针
    *elem = sq->base[sq->head];
    sq->head += 1;

    //出队成功
    return true;
}

bool GetQHead(SeqQueue *sq, QElem *elem)
{
    //队列为空，读取失败
    if (QueueIsEmpty(sq))
        return false;

    //读取队头元素值
    *elem = sq->base[sq->head];

    //读取队头元素值成功
    return true;
}

void PrintQElem(QElem *elem)
{
    //打印队列元素值
    printf("%d\n", *elem);
}

void QueueTraverse(SeqQueue *sq, void (*pFun)(QElem *))
{
    //遍历队列
    for (int i = 0; i < QueueLength(sq); i++)
        pFun(&(sq->base[i]));
}