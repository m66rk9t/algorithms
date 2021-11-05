/*顺序队列实现*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqqueue.h"

bool InitQueue(SeqQueue *sq)
{
    /*为队列分配存储空间*/
    sq->base = (QElem *)malloc(INITQSIZE * sizeof(QElem));

    /*分配失败返回false*/
    if (!sq->base)
        return false;

    /*设置头、尾指针以及最大长度*/
    sq->head = sq->tail = 0;
    sq->maxqsize = INITQSIZE - 1;

    /*初始化成功*/
    return true;
}

void DestoryQueue(SeqQueue *sq)
{
    /*释放动态内存*/
    free(sq->base);
}

bool QueueIsEmpty(SeqQueue *sq)
{
    /*当队头队尾指针相等时，队列为空*/
    if (sq->head == sq->tail)
        return true;
    else
        return false;
}

bool QueueIsFull(SeqQueue *sq)
{
    /*当队尾的下一个元素指针与队头指针相等时，队列已满*/
    if ((sq->tail + 1) % INITQSIZE == sq->head)
        return true;
    else
        return false;
}

int QueueLength(SeqQueue *sq)
{   
    /*计算并返回队列中元素数量*/
    return (((sq->tail - sq->head) + INITQSIZE) % INITQSIZE);
}

bool EnQueue(SeqQueue *sq, QElem *elem)
{
    /*队满，无法入队*/
    if (QueueIsFull(sq))
        return false;
    
    /*元素入队，重置队头指针*/
    sq->base[sq->tail] = *elem;
    sq->tail = (sq->tail + 1) % INITQSIZE;

    /*入队成功*/
    return true;
}

bool DeQueue(SeqQueue *sq, QElem *elem)
{
    /*队空，无法出队*/
    if (QueueIsEmpty(sq))
        return false;

    /*元素出队，重置队尾指针*/
    *elem = sq->base[sq->head];
    sq->head = (sq->head + 1) % INITQSIZE;

    /*出队成功*/
    return true;
}

bool GetQHead(SeqQueue *sq, QElem *elem)
{
    /*队空，无法访问队头元素*/
    if (QueueIsEmpty(sq))
        return false;

    /*访问队头元素*/
    *elem = sq->base[sq->head];

    /*访问成功*/
    return true;
}

void PrintQElem(QElem *elem)
{
    /*打印队列元素值*/
    printf("%-2d", *elem);
}

void QueueTraverse(SeqQueue *sq, void (*pFun)(QElem *))
{
    /*遍历队列，并用pFun指向的函数作用于每个队列元素*/
    for (int i = 0; i < QueueLength(sq); i++)
        pFun(&(sq->base[i]));
}