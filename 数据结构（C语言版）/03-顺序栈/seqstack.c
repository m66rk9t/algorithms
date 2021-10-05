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
    if (!pStack->base && !pStack->top) //判断栈是否已被销毁
        return false;                  //已销栈，销栈失败
    free(pStack->base);                //释放栈占用的内存空间
    pStack->base = pStack->top = NULL; //重置栈底和栈顶指针为NULL，作为已销栈的标志

    return true; //销栈成功
}

bool StackIsNull(SeqStack *pStack)
{
    /*栈底栈顶指针指向同一位置且均不为NULL*/
    if ((pStack->base == pStack->top)&&pStack->base&&pStack->top)
        return true; //空栈
    else
        return false; //栈不为空
}

bool StackIsFull(SeqStack *pStack)
{
    if (StackLength(pStack) == pStack->stacksize)
        return true; //栈满
    else
        return false; //未满
}

unsigned int StackLength(SeqStack *pStack)
{
    if (!pStack->base && !pStack->top) //判断栈是否已被销毁
    {
        fprintf(stderr, "Stack has been destoryed.\n");
        exit(EXIT_FAILURE);
    }
    return (pStack->top - pStack->base); //返回元素数量
}

bool Push(SeqStack *pStack, Elem *pElem)
{
    if (StackIsFull(pStack)) //栈满，追加空间
    {
        pStack->base = (Elem *)realloc(pStack->base, (pStack->stacksize + APPENSIZE) * sizeof(Elem));
        if (pStack->base == NULL) //分配失败
            return false;
        pStack->stacksize += APPENSIZE;                 //设置容量
        pStack->top = pStack->base + pStack->stacksize; //重置栈顶指针
    }
    CopyDataToElem(pStack->top++, pElem); //拷贝数据并入栈

    return true; //入栈成功
}

bool Pop(SeqStack *pStack, Elem *pElem)
{
    if (StackIsNull(pStack))//空栈无法出栈
        return false;

    CopyDataToElem(pElem, pStack->top - 1); //拷贝栈顶元素数据
    pStack->top--;                          //重置栈顶指针

    return true; //出栈成功
}

bool GetTop(SeqStack *pStack, Elem *pElem)
{
    if (StackIsNull(pStack))//空栈无法读取栈顶元素
        return false;

    CopyDataToElem(pElem, pStack->top - 1); //拷贝栈顶元素数据

    return true; //读取成功
}

void PrintElemData(Elem *pElem)
{
    printf("Elemment's value:%d\n", *pElem); //打印元素数据
}

void StackTraverse(SeqStack *pStack, void (*pFun)(Elem *))
{
    Elem *pElem = pStack->top; //指向栈顶元素的下一个位置

    while (--pElem >= pStack->base) //将pFun指向的函数作用于栈中所有元素
        (*pFun)(pElem);
}

void CopyDataToElem(Elem *tar, Elem *src)
{
    *tar = *src; //拷贝数据
}
