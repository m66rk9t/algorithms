/*顺序栈定义*/
#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <stdbool.h>
#define INITSIZE 10
#define APPENSIZE 5

/*类型定义*/
typedef int Elem;
typedef struct sequencestack
{
    Elem *base;             //指向栈底元素
    Elem *top;              //指向栈顶元素的下一个为至
    unsigned int stacksize; //当前已分配的存储空间，以元素为单位
} SeqStack;

/*函数原型*/
/*操作：初始化栈*/
/*前置条件：pStack指向一个栈*/
/*后置条件：将pStack指向的栈初始化为空栈*/
/*        初始化成功返回true，否则返回false*/
bool InitStack(SeqStack *pStack);
/*操作：销毁栈*/
/*前置条件：pStack指向一个栈*/
/*后置条件：销毁pStack指向的栈*/
void DestoryStack(SeqStack *pStack);
/*操作：清空栈*/
/*前置条件：pStack指向的栈不为空*/
/*后置条件：清空pStack指向的栈，将其设为空栈*/
/*        清空成功则返回true，否则返回false*/
bool ClearStack(SeqStack *pStack);
/*操作：判断栈是否为空*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：pStack指向的栈若为空则返回true，否则返回false*/
bool StackIsNull(SeqStack *pStack);
/*操作：判断栈是否已满*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：pStack指向的栈若已满则返回true，否则返回false*/
bool StackIsFull(SeqStack *pStack);
/*操作：统计栈中元素个数*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：返回pStack指向的栈中元素的数量*/
unsigned int StackLength(SeqStack *pStack);
/*操作：入栈*/
/*前置条件：pStack指向一个已初始化的栈*/
/*后置条件：入栈成功则返回true，否则返回false*/
bool Push(SeqStack *pStack, Elem *pElem);
/*操作：出栈*/
/*前置条件：pStack指向一个已初始化且不为空的栈*/
/*后置条件：出栈成功则返回true，否则返回false*/
bool Pop(SeqStack *pStack);
/*操作：读取栈顶元素数据*/
/*前置条件：pStack指向一个已初始化且不为空的栈*/
/*后置条件：将pStack指向的栈顶元素的数据拷贝至pElem指向内存中*/
/*        读取成功则返回true，否则返回false*/
bool GetTop(SeqStack *pStack, Elem *pElem);
/*操作：输出元素数据*/
/*前置条件：pElem指向栈中的元素*/
/*后置条件：输出pElem指向的元素数据*/
void PrintElemData(Elem *pElem);
/*操作：把函数作用于栈中的每个元素*/
/*前置条件：pStack指向一个栈，pFun指向用户指定的函数*/
/*后置条件：将pFun指向的函数作用于pStack指向的栈中的每个元素*/
void StackTraverse(SeqStack *pStack, void (*pFun)(Elem *));
/*操作：拷贝元素数据*/
/*前置条件：tar指向栈中的元素，src指向用户传递的元素参数*/
/*后置条件：将src指向的元素数据拷贝至tar指向的元素中*/
void CopyDataToElem(Elem *tar, Elem *src);

#endif