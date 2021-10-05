/*顺序栈测试-十进制转换成二进制*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqstack.h"

int main(void)
{
    SeqStack ss;                //声明一个栈
    Elem input, reminder, temp; //输入的值、余数以及临时变量
    Elem *pElem;                //指向栈元素的指针
    InitStack(&ss);             //初始化栈

    /*获取输入*/
    printf("Please enter an integer number:");
    while (scanf("%d", &input) != 1 || input <= 0)
        printf("Invalid! Enter again:");
    temp = input;

    /*入栈*/
    while (input)
    {
        reminder = input % 2;
        Push(&ss, &reminder);
        input = input / 2;
    }

    /*出栈*/
    printf("%d to binary:", temp);
    pElem = ss.top;
    while (--pElem >= ss.base)
    {
        Pop(&ss, &reminder);
        printf("%d", reminder);
    }
    putchar('\n');

    /*销毁*/
    DestoryStack(&ss);

    return 0;
}