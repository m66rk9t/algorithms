/*顺序栈的实现*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqstack.h"

/*函数定义*/
bool InitStack(SeqStack *pStack)
{
    pStack->base = (Elem *)malloc(INITSIZE * sizeof(Elem)); //为栈分配存储空间
    if (pStack->base == NULL)                               //分配存储空间失败，初始化失败
        return false;
    pStack->top = pStack->base;   //设置栈底和栈顶指针，将栈设置为空栈
    pStack->stacksize = INITSIZE; //设置栈的容量

    return true; //初始化成功
}

bool DestoryStack(SeqStack *pStack)
{
    Elem *delElem; //储存待删元素的地址

    if (pStack->base == pStack->top) //空栈情况
        free(pStack->base);
    else
        while ((delElem = --(pStack->top)) >= pStack->base)
            free(delElem);

    /*
    if (pStack->base == pStack->top)
        free(pStack->base);
    else
        while((pStack->top)-- >= pStack->base)
            free(pStack->top);
    */

    return true;
}

bool StackIsNull(SeqStack *pStack)
{
    if (pStack->base == pStack->top)
        return true; //空栈
    else
        return false; //栈不为空
}

bool StackIsFull(SeqStack *pStack)
{
    if (StackLength(&ss))}

unsigned int StackLength(SeqStack *pStack)
{
    return (pStack->top - pStack->base) / sizeof(Elem);
}
