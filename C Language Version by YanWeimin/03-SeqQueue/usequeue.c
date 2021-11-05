// 使用顺序队列解决约瑟夫环问题：
// 现有T个人围成一桌坐下，编号从1到T，从编号为1的人开始报数。
// 报数也从1开始，报到M的人离席，从离席者的下一位在座成员开始，继续从1开始报数。
// 复现这个过程（各成员的离席次序），或者求最后一个在座的成员编号。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqqueue.h"

int main(void)
{
    SeqQueue sq;
    QElem q = 1;
    int count = 0;

    InitQueue(&sq);
    for (int i = 0; i < sq.maxqsize; i++, q++)
        EnQueue(&sq, &q);

    while (QueueLength(&sq) != 1)
    {
        DeQueue(&sq, &q);
        count++;
        if (count == 3)
        {
            printf("%d ", q);
            count = 0;
            continue;
        }
        else
            EnQueue(&sq, &q);
    }
    DeQueue(&sq, &q);
    printf("%d ", q);

    return 0;
}