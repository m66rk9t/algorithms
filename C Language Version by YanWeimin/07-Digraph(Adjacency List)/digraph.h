/*无权有向图邻接表定义*/
#ifndef DIGRAPH_H
#define DIGRAPH_H

/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*无权有向图邻接表类型定义*/
typedef char Ver; //顶点数据的类型定义
typedef struct vertexnode
{
    Ver arctail;              //弧尾顶点
    struct arcnode *firstarc; //顶点的第一条弧
} VertexNode;                 //顶点节点结构定义
typedef struct arcnode
{
    Ver archead;             //弧头顶点
    struct arcnode *nextarc; //顶点的下一条弧
} ArcNode;                   //弧节点结构定义
typedef struct adjlist
{
    int vers;            //顶点数
    int arcs;            //弧数
    VertexNode *verlist; //顶点顺序表
} AdjList;               //邻接表结构定义
typedef struct pari
{
    ArcNode *pre; //前一个弧节点
    ArcNode *cur; //当前弧节点
} Pair;           //弧节点指针对结构定义

/*函数原型*/
/*操作：初始化邻接表*/
/*前置条件：adj指向一个未初始化的邻接表*/
/*后置条件：初始化adj指向的邻接表中的顶点顺序表*/
/*        初始化成功返回true，否则返回false*/
bool InitAdjList(AdjList *adj);
/*操作：初始化顶点顺序表*/
/*前置条件：newverlist指向一个未初始化的顶点顺序表*/
/*后置条件：初始化newverlist指向的顶点顺序表*/
/*        初始化成功返回true，否则返回false*/
static bool InitVerList(AdjList *adj);
/*操作：初始化弧节点链表*/
/*前置条件：newarclist指向一个未初始化的弧节点接表*/
/*后置条件：初始化newarclist指向的弧节点链表*/
/*        初始化成功返回true，否则返回false*/
static bool InitArcList(AdjList *adj);
/*操作：销毁邻接表*/
/*前置条件：adj指向一个已初始化的邻接表*/
/*后置条件：销毁adj指向的邻接表*/
void DestoryAdjList(AdjList *adj);
/*操作：添加弧*/
/*前置条件：adj指向一个已初始化的邻接表，tail和head分别指向待添加弧的弧尾和弧头顶点*/
/*后置条件：将以*tail和*head为弧为和弧头的弧添加到adj指向的临济表中*/
bool AddArc(AdjList *adj, Ver *tail, Ver *head);
/*操作：定位顶点索引*/
/*前置条件：adj指向一个已初始化的邻接表，ver指向待查找的顶点*/
/*后置条件：定位成功则返回顶点索引，否则*pos为-1*/
int LocateVertex(AdjList *adj, Ver *ver);
/*操作：定位弧节点*/
/*前置条件：adj指向一个已初始化的邻接表，*/
/*        tail和head分别指向待定位弧节点的弧尾和弧头顶点*/
/*后置条件：返回待定位弧节点指针及其前一个弧节点指针对*/
Pair LocateArc(AdjList *adj, Ver *tail, Ver *head);
/*操作：获取顶点和弧的数量*/
/*前置条件：adj指向一个未初始化的邻接表*/
/*后置条件：初始化adj指向的邻接表的vers和arcs成员*/
static void GetVersArcs(AdjList *adj);
/*操作：获取弧头和弧尾顶点*/
/*前置条件：tail和head指向待获取的顶点*/
/*后置条件：用tail和head返回获取的顶点*/
static void GetArc(Ver *tail, Ver *head);
/*操作：清理输入*/
/*前置条件：无*/
/*后置条件：清理输入缓冲区中的多余数据*/
static void ClearInput();
/*操作：初始化弧节点*/
/*前置条件；*newarc指向待初始化的弧节点，head指向该弧的弧头顶点*/
/*后置条件：初始化newarc指向的弧节点，其弧头顶点为*head*/
/*        初始化成功返回true，否则返回false*/
static bool InitArcNode(ArcNode **newarc, Ver *head);

#endif