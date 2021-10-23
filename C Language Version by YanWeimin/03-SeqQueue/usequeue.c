#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqqueue.h"

int main(void)
{
    SeqQueue sq;
    QElem elem = 1;

    InitQueue(&sq);
    
    for (int i = 0; i < sq.maxqsize; i++, elem++)
        EnQueue(&sq, &elem);

    QueueTraverse(&sq, PrintQElem);

    DestoryQueue(&sq);



    return 0;
}