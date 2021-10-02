/*顺序栈实现*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "seqstack.h"

bool InitStack(SeqStack *pStack)
{
    if (!StackIsNull(pStack))
        DestoryStack(pStack);
    pStack->base = (Elem *)malloc(INITSIZE * sizeof(Elem));
    if (!pStack->base)
        return false;
    pStack->top = pStack->base;
    pStack->stacksize = INITSIZE;

    return true;
}

void DestoryStack(SeqStack *pStack)
{
    free(pStack->base);
    pStack->base = NULL;
}

bool ClearStack(SeqStack *pStack)
{
    Elem *pDelElem, *pNextElem;

    if (StackIsNull(pStack))
        return false;

    pNextElem = pStack->top - 1;

    while (pNextElem >= pStack->base)
    {
        pDelElem = pNextElem--;
        free(pDelElem);
    }

    return true;
}

bool StackIsNull(SeqStack *pStack)
{
    if (pStack->base == pStack->top)
        return true;
    else
        return false;
}

bool StackIsFull(SeqStack *pStack)
{
    if (StackLength(pStack) == pStack->stacksize)
        return true;
    else
        return false;
}

unsigned int StackLength(SeqStack *pStack)
{
    return pStack->top - pStack->base;
}

bool Push(SeqStack *pStack, Elem *pElem)
{
    if (StackIsFull(pStack))
    {
        pStack->base = (Elem *)realloc(pStack->base,
                                       (pStack->stacksize + APPENSIZE) * sizeof(Elem));
        if (!pStack->base)
            return false;
        pStack->stacksize += APPENSIZE;
        pStack->top = pStack->base + pStack->stacksize - 1;
    }
    CopyDataToElem(pStack->top, pElem);
    pStack->top++;

    return true;
}

bool Pop(SeqStack *pStack)
{
    Elem *pDelElem;
    if (StackIsNull(pStack))
        return false;
    pDelElem = pStack->top - 1;
    pStack->top--;
    free(pDelElem);

    return true;
}

bool GetTop(SeqStack *pStack, Elem *pElem)
{
    if (StackIsNull(pStack))
        return false;
    CopyDataToElem(pElem, pStack->top - 1);

    return true;
}

void PrintElemData(Elem *pElem)
{
    printf("Elem:%d\n", *pElem);
}

void StackTraverse(SeqStack *pStack, void (*pFun)(Elem *))
{
    Elem *pElem = pStack->top - 1;

    while (pElem >= pStack->base)
    {
        (*pFun)(pElem);
        pElem--;
    }
}

void CopyDataToElem(Elem *tar, Elem *src)
{
    *tar = *src;
}