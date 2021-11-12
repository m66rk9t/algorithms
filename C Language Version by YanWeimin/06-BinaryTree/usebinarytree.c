#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void)
{
    BinaryTree myTree;
    NodeType nodes[10] = {10, 5, 6, 9, 11, 2, 0, 1, 4, 3};
    
    InitTree(&myTree);//初始化二叉树
    
    for (int i = 0; i < 10; i++)//插入节点
        AddNode(&myTree, &nodes[i]);
    
    /*先序、中序、后序遍历*/
    PreOrder(&myTree, PrintNodeData);
    putchar('\n');
    InOrder(&myTree, PrintNodeData);
    putchar('\n');
    PostOrder(&myTree, PrintNodeData);
    putchar('\n');

    DestoryTree(&myTree);//销毁二叉树

    return 0;
}