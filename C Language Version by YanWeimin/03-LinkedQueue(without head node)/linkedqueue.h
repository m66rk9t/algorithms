/*链式队列定义*/
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <stdbool.h>

/*链式栈类型定义*/
static int QueueStatus = 0;
typedef int NodeType; //队列中节点数据域的类型
typedef struct queuenode
{
    NodeType data;          //队列节点数据域
    struct queuenode *next; //队列节点指针域
} QueueNode;                //队列节点结构
typedef struct linkedqueue
{
    QueueNode *head; //队头节点指针
    QueueNode *tail; //队尾节点指针
} LinkedQueue;       //队列结构

/*函数原型*/
/*操作：初始化队列*/
/*前置条件：lq指向一个未初始化的队列*/
/*后置条件：将lq指向的队列初始化未空队列，*/
/*         初始化成功返回true，若已初始化则异常结束程序*/
bool InitQueue(LinkedQueue *lq);
/*操作：销毁队列*/
/*前置条件：lq指向一个已初始化的队列*/
/*后置条件：释放lq指向的队列使用的存储空间*/
void DstoryQueue(LinkedQueue *lq);
/*操作：判断队列是否为空*/
/*前置条件：lq指向一个已初始化的队列*/
/*后置条件：lq指向的队列为空返回ture，否则返回false*/
bool QueueIsEmpty(LinkedQueue *lq);
/*操作：判断队列是否已满*/
/*前置条件：lq指向一个已初始化的队列*/
/*后置条件：lq指向的队列已满返回true，否则返回false*/
bool QueueIsFull(LinkedQueue *lq);
/*操作：清空队列*/
/*前置条件：lq指向一个已初始化且不为空的队列*/
/*后置条件：清空lq指向的队列，清空成功返回true，否则返回false*/
bool ClearQueue(LinkedQueue *lq);
/*操作：计算队列长度*/
/*前置条件：lq指向一个已初始化的队列*/
/*后置条件：返回lq指向的队列的长度*/
unsigned int QueueLength(LinkedQueue *lq);
/*操作：入队*/
/*前置条件：lq指向一个已初始化且未满的队列*/
/*后置条件：将node指向的值链接到队尾，*/
/*         入队成功返回true，否则返回false*/
bool EnQueue(LinkedQueue *lq, QueueNode *node);
/*操作：出队*/
/*前置条件：lq指向一个已初始化且不为空的队列*/
/*后置条件：用node返回队头节点的值*/
/*         出队成功返回true，否则返回false*/
bool DeQueue(LinkedQueue *lq, QueueNode *node);
/*操作：读取队头节点*/
/*前置条件：lq指向一个已初始化且不为空的队列*/
/*后置条件：用node返回队头节点的值*/
/*         读取成功返回true，否则返回false*/
bool GetHead(LinkedQueue *lq, QueueNode *node);
/*操作：打印节点值*/
/*前置条件：node指向队列中的节点*/
/*后置条件：打印node指向节点的值*/
void PrintQNodeData(QueueNode *node);
/*操作：遍历队列*/
/*前置条件：lq指向一个已初始化的队列*/
/*后置条件：将pFun指向的函数作用于队列中的每个节点*/
void QueueTraverse(LinkedQueue *lq, void (*pFun)(QueueNode *));
/*操作：拷贝节点信息*/
/*前置条件：tar指向目标节点，src指向源节点*/
/*后置条件：将src节点的信息拷贝至tar节点*/
void CopyNodeData(QueueNode *tar, QueueNode *src);
/*操作：处理错误信息*/
/*前置条件：statuscode为队列当前的状态：已初始化、未初始化，已被宏定义*/
/*后置条件：提示用户错误信息并退出程序*/
void Error(int statuscode);

#endif