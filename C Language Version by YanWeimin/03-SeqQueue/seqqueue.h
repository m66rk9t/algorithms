/*队列的顺序存储结构*/
/*使用一维数组实现，不使用最后一个元素*/
#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include <stdbool.h>

/*顺序存储结构定义*/
typedef int QElem;  //队列元素
#define MAXQSIZE 11 //队列大小
typedef struct seqqueue
{
    QElem *base; //指向动态分配内存
    int head;    //指向队头
    int tail;    //指向队尾的下一个位置
    int maxqsize;//队列大小
} SeqQueue;      //队列结构

/*函数原型*/
/*操作：初始化队列*/
/*前置条件：sq指向一个未初始化且不为空的队列*/
/*后置条件：将sq指向的队列初始化为空队列*/
/*         初始化成功返回true，否则返回false*/
bool InitQueue(SeqQueue *sq);
/*操作：判断队列是否为空*/
/*前置条件：sq指向一个已初始化的队列*/
/*后置条件：sq指向的队列为空则返回true，否则返回false*/
bool QueueIsEmpty(SeqQueue *sq);
/*操作：判断队列是否已满*/
/*前置条件：sq指向一个已初始化的队列*/
/*后置条件：sq指向的队列已满则返回true，否则返回false*/
bool QueueIsFull(SeqQueue *sq);
/*操作：计算队列长度*/
/*前置条件：sq指向一个已初始化的队列*/
/*后置条件：返回队列中元素的数量*/
int QueueLength(SeqQueue *sq);
/*操作：入队*/
/*前置条件：sq指向一个已初始化且未满的队列*/
/*后置条件：将elem指向的值入队*/
/*         入队成功返回true，否则返回false*/
bool EnQueue(SeqQueue *sq, QElem *elem);
/*操作：出队*/
/*前置条件：sq指向一个已初始化且不为空的队列*/
/*后置条件：将队头元素出队，并用elem返回其值*/
/*         出队成功返回true，否则返回false*/
bool DeQueue(SeqQueue *sq, QElem *elem);
/*操作：打印队列元素值*/
/*前置条件：elem指向队列中的元素*/
/*后置条件：打印elem指向的元素值*/
void PrintQElem(QElem *elem);
/*操作：遍历队列*/
/*前置条件：sq指向一个已初始化的队列*/
/*后置条件：将pFun指向的函数作用于队列中的每个元素*/
void QueueTraverse(SeqQueue *sq, void(*pFun)(QElem *));

#endif