/*链式栈定义*/
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <stdbool.h>

/*类型定义*/
typedef struct studentInfo
{
    int id;
    struct studentInfo *next;
} Node; //链式栈节点结构
typedef struct linkedstack
{
    Node *base; //指向栈底节点的指针
    Node *top;  //指向栈顶节点的指针
} LinkedStack;  //链式栈结构

/*函数原型*/
/*操作：初始化栈*/
/*前置条件：pStack指向一个链式栈*/
/*后置条件：将pStack指向的栈初始化为空栈，*/
/*        若pStack指向的栈不为空则销毁后再初始化为空栈*/
void InitStack(LinkedStack *pStack);
/*操作：销毁栈*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：pStack指向的栈被销毁，被设为空栈*/
void DestoryStack(LinkedStack *pStack);
/*操作：判断栈是否为空*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：pStack指向的栈若为空返回true，否则返回false*/
bool StackIsNull(LinkedStack *pStack);
/*操作：判断是否已无再为栈分配空间的可用内存*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：pStack指向的栈已满则返回true，否则返回false*/
bool StackIsFull(LinkedStack *pStack);
/*操作：统计栈中节点个数*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：返回pStack指向的栈的节点个数*/
unsigned int StackLength(LinkedStack *pStack);
/*操作：入栈*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：向pStack指向的栈的栈顶插入节点*/
/*        入栈成功返回true，否则返回false*/
bool Push(LinkedStack *pStack, Node *pNode);
/*操作：出栈*/
/*前置条件：pStack指向一个已初始化且不为空的栈*/
/*后置条件：删除pStack指向的栈的栈顶节点*/
/*        出栈成功返回true，否则返回false*/
bool Pop(LinkedStack *pStack);
/*操作：取栈顶节点数据*/
/*前置条件：pStack指向的栈不为空*/
/*后置条件：将pStack指向的栈的栈顶节点数据拷贝至pNode指向的节点中，*/
/*        若栈空则返回false，读取成功则返回true*/
bool GetTop(LinkedStack *pStack, Node *pNode);
/*操作：拷贝节点数据*/
/*前置条件：tar指向栈中的指定节点，src指向用户传递的节点*/
/*后置条件：将src指向的节点中的数据拷贝至tar指向的节点中*/
void CopyDataToNode(Node *tar, Node *src);
/*操作：打印节点数据*/
/*前置条件：pNode指向栈中的一个节点*/
/*后置条件：打印pNode指向的节点的数据*/
void PrintNodeData(Node *pNode);
/*操作：把函数作用于栈中的每个节点*/
/*前置条件：pStack指向一个已初始化且不为空的栈*/
/*后置条件：将pFun指向的函数作用于pStack指向的栈中的每个节点*/
void StackTraverse(LinkedStack *pStack, void (*pFun)(Node *));

#endif