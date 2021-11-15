/*使用有向图的邻接矩阵*/
#include <stdio.h>
#include <stdbool.h>
#include "digraph.h"

int main(void)
{
    Digraph dg;
    int od = 0, id = 0;
    CreateGraph(&dg);
    printf("The digraph has initialized.\n");
    printf("The martix of the digraph:\n");
    PrintMatrix(&dg);
    ClearMatrix(&dg);
    printf("After emptying the matrix:\n");
    PrintMatrix(&dg);
    return 0;
}