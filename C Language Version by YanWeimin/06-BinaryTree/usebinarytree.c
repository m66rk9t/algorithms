/*使用二叉树*/
#include <stdio.h>
#include "binarytree.h"

int main(void)
{
    BinaryTree myTree;                                            //声明二叉树
    NodeType nodes[11] = {10, 0, 2, 4, 6, 8, 12, 14, 16, 18, 20}; //初始化节点数据数组
    NodeType myNode = 10;
    /*初始化二叉树*/
    InitTree(&myTree);

    /*插入节点*/
    for (int i = 0; i < 11; i++)
        AddNode(&myTree, &nodes[i]);

    /*中序遍历二叉树*/
    InOrder(&myTree, PrintNodeData);

    /*删除节点并中序遍历二叉树*/
    DeleteNode(&myTree, &myNode);
    putchar('\n');
    InOrder(&myTree, PrintNodeData);

    /*销毁二叉树*/
    DestoryTree(&myTree);

    return 0;
}