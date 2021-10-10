/*顺序栈定义*/
#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <stdbool.h>
#define INITSIZE 10 //栈初始容量
#define APPENSIZE 5 //可追加容量

/*类型定义*/
typedef int Elem; //栈中元素的类型
typedef struct sequencestack
{
    Elem *base;             //指向栈底元素
    Elem *top;              //指向栈顶元素的下一个位置
    unsigned int stacksize; //当前已分配的存储空间，以元素为单位
} SeqStack;                 //栈结构

/*函数原型*/
/*操作：初始化栈*/
/*前置条件：pStack指向一个栈*/
/*后置条件：将pStack指向的栈初始化为空栈*/
/*        初始化成功则返回true，否则返回false*/
bool InitStack(SeqStack *pStack);
/*操作：销毁栈*/
/*前置条件：pStack指向一个栈*/
/*后置条件：销毁pStack指向的栈，将栈底栈顶指针设置为NULL，*/
/*         销栈成功则返回true，若栈已被销毁则返回false*/
bool DestoryStack(SeqStack *pStack);
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
/*前置条件：pStack指向一个已初始化的栈，*/
/*         pElem指向待入栈的元素*/
/*后置条件：入栈成功则返回true，否则返回false*/
bool Push(SeqStack *pStack, Elem *pElem);
/*操作：出栈*/
/*注意：顺序栈与链式栈的出栈操作不同，*/
/*     顺序栈不能用free()释放栈顶元素，*/
/*     链式栈可以用free()释放栈顶元素，*/
/*     因为free()不能释放动态分配的内存中的部分内存*/
/*前置条件：pStack指向一个已初始化且不为空的栈，*/
/*         将出栈元素的数据拷贝至pElem指向的内存中*/
/*后置条件：出栈成功则返回true，否则返回false*/
bool Pop(SeqStack *pStack, Elem *pElem);
/*操作：读取栈顶元素数据*/
/*前置条件：pStack指向一个已初始化且不为空的栈*/
/*后置条件：将栈顶元素的数据拷贝至pElem指向的内存中*/
/*        读取成功则返回true，否则返回false*/
bool GetTop(SeqStack *pStack, Elem *pElem);
/*操作：输出元素数据*/
/*前置条件：pElem指向栈中的元素*/
/*后置条件：输出pElem指向的元素的数据*/
void PrintElemData(Elem *pElem);
/*操作：把函数作用于栈中的每个元素*/
/*前置条件：pStack指向一个栈，pFun指向用户指定的函数*/
/*后置条件：将pFun指向的函数作用于pStack指向的栈中的每个元素*/
void StackTraverse(SeqStack *pStack, void (*pFun)(Elem *));
/*操作：拷贝元素数据*/
/*前置条件：tar指向目标元素，src指向源元素*/
/*后置条件：将src指向的元素数据拷贝至tar指向的元素中*/
void CopyDataToElem(Elem *tar, Elem *src);

#endif