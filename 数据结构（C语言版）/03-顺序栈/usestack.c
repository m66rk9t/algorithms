/*顺序栈测试-十进制转换成二进制*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqstack.h"

int main(void)
{
    SeqStack ss;
    Elem input, reminder;

    InitStack(&ss); //初始化栈

    /*获取输入*/
    printf("Please enter an integer number:");
    while (scanf("%d", &input) != 1 || input <= 0)
        printf("Invalid! Enter again:");
    
    /*转换进制，入栈*/
    while (input)
    {
        reminder = input % 2;
        Push(&ss, &reminder);
        input = input / 2;
    }

    /*出栈，打印数据*/
    StackTraverse(&ss, PrintElemData);
    
    /*销毁栈*/
    DestoryStack(&ss);

    return 0;
}