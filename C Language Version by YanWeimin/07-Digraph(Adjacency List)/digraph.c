/*无权有向图邻接表实现*/
/*包含头文件*/
#include "digraph.h"

/*函数定义*/
bool InitAdjList(AdjList *adj)
{
}

static bool InitVerList(AdjList *adj)
{
    /*获取顶点和弧的数量*/
    GetVersArcs(adj);

    /*为顶点顺序表分配内存*/
    adj->verlist = (VertexNode *)malloc(adj->vers * sizeof(VertexNode));

    /*初始化失败*/
    if (adj->verlist == NULL)
        return false;

    /*初始化顶点顺序表*/
    printf("Please enter %d vertices now: ", adj->vers);
    for (int i = 0; i < adj->vers; i++)
    {
        adj->verlist[i].arctail = getchar();
        adj->verlist[i].firstarc = NULL;
    }

    /*初始化成功*/
    return true;
}

/*重点*/
static bool InitArcList(AdjList *adj)
{
    Ver arctail, archead;
    int verpos = -1, arccount = adj->arcs;

    /*插入弧节点*/
    while (arccount--)
    {
        /*调用GetArc()输入弧头弧尾*/
        /*调用LocateVertex()弧尾顶点不存在则重新输入*/
        /*调用AddArc()插入*/
        /*插入失败返回false*/
        /*插入成功返回true*/
    }

    /*初始化成功*/
    return true;
}

/*需要修改*/
void DestoryAdjList(AdjList *adj)
{
    free(adj->verlist);
}

bool AddArc(AdjList *adj, Ver *tail, Ver *head)
{
    ArcNode *newarcnode;
    Pair find;

    /*初始化弧节点并判断是否成功*/
    if (!InitArcNode(&newarcnode, head))
        return false;

    /*定位弧节点*/
    find = LocateArc(adj, tail, head);
    if (!find.pre && !find.cur) //作为第一条弧插入
        adj->verlist[*tail].firstarc = newarcnode;
    else if (find.pre && find.cur) //该弧已存在
        return false;
    else //作为新弧插入
        find.pre->nextarc = newarcnode;

    /*添加成功*/
    return true;
}

int LocateVertex(AdjList *adj, Ver *ver)
{
    /*定位指定顶点在顶点顺序表中的索引*/
    for (int i = 0; i < adj->vers; i++)
        if (adj->verlist[i].arctail == *ver)
            return i; //返回索引

    /*定位失败*/
    return -1;
}

Pair LocateArc(AdjList *adj, Ver *tail, Ver *head)
{
    /*声明待查找弧节点对*/
    Pair find;

    /*初始化待查找弧节点对*/
    find.pre = find.cur = adj->verlist[*tail].firstarc;

    /*查找弧节点*/
    while (find.cur)
    {
        if (find.cur->archead == *head) //查找成功
            break;
        find.pre = find.cur;
        find.cur = find.cur->nextarc;
    }

    /*返回弧节点对*/
    return find;
}

static void GetVersArcs(AdjList *adj)
{
    /*获取顶点和弧的数量*/
    printf("Please enter the number of vertices and arcs\
(sprated by blank):");
    scanf("%d %d", adj->vers);
    scanf("%d %d", adj->arcs);

    /*清理输入行*/
    ClearInput();
}

static void GetArc(Ver *tail, Ver *head)
{
    /*获取弧头弧尾节点*/
    printf("Please enter an arc(arctail,archead): ");
    scanf("%c,%c", tail, head);

    /*清理输入行*/
    ClearInput();
}

static void ClearInput()
{
    /*清理输入行*/
    while (getchar() != '\n')
        continue;
}

static bool InitArcNode(ArcNode **newarc, Ver *head)
{
    /*为新弧节点分配内存*/
    *newarc = (ArcNode *)malloc(sizeof(ArcNode));

    /*初始化失败*/
    if (*newarc == NULL)
        return false;

    /*初始化弧节点*/
    (*newarc)->archead = *head;
    (*newarc)->nextarc = NULL;

    /*初始化成功*/
    return true;
}