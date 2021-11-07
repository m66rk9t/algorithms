/*无权有向图的邻接矩阵定义*/
#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdbool.h>

/*有向图类型定义*/
#define MAXVER 6   //最大顶点数量
typedef char Elem; //顶点数据类型
typedef struct vertex
{
    int no;    //顶点编号
    Elem elem; //顶点信息
} Vertex;      //顶点结构
typedef struct digraph
{
    int vers, arcs;            //顶点数量以及弧的数量
    Vertex vertices[MAXVER];   //顶点数组
    int edges[MAXVER][MAXVER]; //邻接矩阵二维数组
} Digraph;                     //有向图邻接矩阵结构

/*函数定义*/
/*操作：建立无权有向图的邻接矩阵*/
/*前置条件：dg指向一个未初始化的无权有向图邻接矩阵*/
/*后置条件：dg指向一个已初始化的无权有向图邻接矩阵*/
/*        建表成功则返回true，否则返回false*/
bool CreateGraph(Digraph *dg);
/*操作：清空邻接矩阵*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵*/
/*后置条件：将dg指向的无权有向图邻接矩阵置为全0*/
void ClearMatrix(Digraph *dg);
/*操作：求无权有向图中某顶点的出度*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵，*/
/*        verNo是某顶点的编号*/
/*后置条件：计算并返回verNo的出度*/
int OutDegree(Digraph *dg, int verNo);
/*操作：求无权有向图中某顶点的入度*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵，*/
/*        verNo是某顶点的编号*/
/*后置条件：计算并返回verNo的入度*/
int InDegree(Digraph *dg, int verNo);
/*操作：判断弧是否存在*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵，*/
/*        tail与head分别为两个顶点编号*/
/*后置条件：若弧存在则返回true，否则返回false*/
bool IsArcExist(Digraph *dg, int tail, int head);
/*操作：添加弧*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵，*/
/*        tail与head分别为两个顶点编号*/
/*后置条件：在以tail为弧尾，以head为弧头的两个顶点间添加一条弧，*/
/*添加成功则返回true，否则返回false*/
bool AddArc(Digraph *dg, int tail, int head);
/*操作：删除弧*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵，*/
/*        tail与head分别为两个顶点编号*/
/*后置条件：删除以tail为弧尾，以head为弧头的两个顶点间的一条弧，*/
/*删除成功则返回true，否则返回false*/
bool DeleteArc(Digraph *dg, int tail, int head);
/*操作：打印无权有向图的邻接矩阵*/
/*前置条件：dg指向一个已初始化的无权有向图邻接矩阵*/
/*后置条件：打印出dg指向的无权有向图邻接矩阵*/
void PrintMatrix(Digraph *dg);

#endif