/*无权有向图邻接表实现*/
/*包含头文件*/
#include "digraph.h"

/*函数定义*/
bool InitAdjList(AdjList * adj)
{
    int ask_vers, ask_arcs;
    
    /*输入顶点数和弧数*/
    printf("Please enter the count of vertexs and ars \
(Separated by blank): ");
    scanf("%d %d", &ask_vers, &ask_arcs);

    /*初始化邻接表的顶点数和弧数*/
    adj->vers = ask_vers;
    adj->arcs = ask_arcs;

    /*清理输入行*/
    while (getchar() != '\n')
        continue;
    
    /*为顶点链表分配内存*/
    adj->verlist = (VertexNode *)malloc(adj->vers * sizeof(VertexNode));

    /*初始化失败*/
    if (!adj->verlist)
    {
        fprintf(stderr, "Initialization failed.\n");
        return false;
    }

    /*初始化顶点链表*/
    printf("Please enter %d vertexs' character: ", adj->vers);
    for (int i = 0; i < adj->vers; i++)
    {
        adj->verlist[i].arctail = getchar();
        adj->verlist[i].firstarc = NULL;
    }

    /*清理输入行*/
    while (getchar() != '\n')
        continue;

    /*初始化成功*/
    return true;
}

bool FillAdjList(AdjList *adj)
{
    ArcNode * newarc, temp;
    Ver head, tail, verpos = -1;
    int count = adj->arcs;
    

    /*完善弧节点表*/
    while (count--)
    {
        /*输入弧头和弧尾顶点*/
        while (verpos < 0)
        {
            /*输入弧头弧尾节点*/
            printf("Please enter an arc(arctail,archead): ");
            scanf("%c,%c", &tail, &head);

            /*清理输入行*/
            while (getchar() != '\n')
                continue;
            
            /*定位顶点索引*/
            verpos = LocateVertex(adj, &tail);
        }

        
    }


    /*完善成功*/
    return true;
}

void DestoryAdjList(AdjList *adj)
{
    free(adj->verlist);
}

int LocateVertex(AdjList *adj, Ver *ver)
{
    for (int i = 0; i < adj->vers; i++)
        if (adj->verlist[i].arctail == *ver)
            return i;

    return -1;
}