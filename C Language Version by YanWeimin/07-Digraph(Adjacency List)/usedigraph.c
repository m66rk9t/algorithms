#include <stdio.h>
#include "digraph.h"

int main(void)
{
    AdjList myAdj;
    if (InitAdjList(&myAdj))
        printf("Success.\n");
    else
        printf("Failed.\n");
    return 0;
}