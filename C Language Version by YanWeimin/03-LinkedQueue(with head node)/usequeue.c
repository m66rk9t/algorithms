// 使用链式队列解决约瑟夫环问题：
// 现有T个人围成一桌坐下，编号从1到T，从编号为1的人开始报数。
// 报数也从1开始，报到M的人离席，从离席者的下一位在座成员开始，继续从1开始报数。
// 复现这个过程（各成员的离席次序），或者求最后一个在座的成员编号。
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linkedqueue.h"
#define MEMBER 10
#define EXITNUM 3

int main(void)
{
    LinkedQueue lq;
    QueueNode qn;
    int count = 1;

    qn.data = 1;
    
    InitQueue(&lq);
    
    for (int i = 0; i < MEMBER; i++, qn.data++)
        EnQueue(&lq, &qn);

    puts("Dequeue order:");
    
    while (QueueLength(&lq) != 1)
    {
        DeQueue(&lq, &qn);
        if (count == EXITNUM)
        {
            printf("%-2d", qn.data);
            count = 1;
            continue;
        }
        EnQueue(&lq, &qn);
        count++;
    }
    DeQueue(&lq, &qn);
    printf("\nThe last one's order:%-2d\n", qn.data);

    DstoryQueue(&lq);

    return 0;
}