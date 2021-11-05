/*无权有向图的邻接矩阵实现*/
#include <stdio.h>
#include <stdbool.h>
#include "digraph.h"

bool CreateGraph(Digraph *dg)
{
    int v1 = 0, v2 = 0;
    /*输入顶点数和弧数*/

    printf("Please enter the number of vertices: ");
    scanf("%d", &dg->vers);
    printf("Please enter the number of arcs: ");
    scanf("%d", &dg->arcs);

    /*清理输入行*/
    while (getchar() != '\n')
        continue;

    /*输入顶点信息并初始化顶点数组*/
    for (int i = 0; i < dg->vers; i++)
    {
        printf("Please enter a character as the symbol of vertex: ");
        dg->vertices[i].elem = getchar();
        /*清理输入行*/
        while (getchar() != '\n')
            continue;
    }

    /*初始化邻接矩阵*/
    for (int r = 0; r < MAXVER; r++)
        for (int c = 0; c < MAXVER; c++)
            dg->edges[r][c] = 0;

    /*输入顶点并构造弧*/
    printf("Please enter a set of vertices like 0,1: ");
    for (int i = 0; i < dg->arcs; i++)
    {
        scanf("%d,%d", &v1, &v2);
        if (dg->edges[v1][v2] == 0)
            dg->edges[v1][v2] = 1;
        printf("Enter the next group: ");
    }

    return true;
}

void PrintMatrix(Digraph *dg)
{
    for (int r = 0; r < MAXVER; r++)
    {
        for (int c = 0; c < MAXVER; c++)
            printf("%-2d", dg->edges[r][c]);
        putchar('\n');
    }
}