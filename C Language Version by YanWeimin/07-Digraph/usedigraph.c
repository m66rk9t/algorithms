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
    od = OutDegree(&dg, 2);
    id = InDegree(&dg, 2);
    printf("Out degree:%d\nIn degree:%d\n", od, id);

    return 0;
}