/*使用有向图的邻接矩阵*/
#include <stdio.h>
#include <stdbool.h>
#include "digraph.h"

int main(void)
{
    Digraph dg;
    CreateGraph(&dg);
    printf("The martix of the digraph:\n");
    PrintMatrix(&dg);

    return 0;
}