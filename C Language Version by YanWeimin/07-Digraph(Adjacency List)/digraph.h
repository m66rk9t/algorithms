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
    VertexNode *verlist; //顶点链表
} AdjList;               //邻接表结构定义

/*函数原型*/
/*操作：初始化邻接表*/
/*前置条件：adj指向一个未初始化的邻接表*/
/*后置条件：初始化adj指向的邻接表中的顶点链表*/
/*        初始化成功返回true，否则返回false*/
bool InitAdjList(AdjList *adj);
/*操作：完善邻接表*/
/*前置条件：adj指向一个已初始化的邻接表*/
/*后置条件：完善邻接表的弧节点表*/
/*        完善成功返回true，否则返回false*/
bool FillAdjList(AdjList *adj);
/*操作：销毁邻接表*/
/*前置条件：adj指向一个已初始化的邻接表*/
/*后置条件：销毁adj指向的邻接表*/
void DestoryAdjList(AdjList *adj);
/*操作：定位顶点索引*/
/*前置条件：adj指向一个已初始化的邻接表，find指向待查找的顶点*/
/*后置条件：定位成功则返回顶点索引，否则*pos为-1*/
int LocateVertex(AdjList *adj, Ver *ver);

#endif