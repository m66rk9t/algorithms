/*二叉树实现*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"

/*函数定义*/
void InitTree(BinaryTree *tree)
{
    /*设置为空树*/
    *tree = NULL;
}

void DestoryTree(BinaryTree *tree)
{
    /*后序遍历，释放节点的内存*/
    if ((*tree)->ltree)
        DestoryTree(&((*tree)->ltree));
    if ((*tree)->rtree)
        DestoryTree(&((*tree)->rtree));
    free(*tree);
}

TreeNode *CreateNode(NodeType *data)
{
    /*创建节点*/
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));

    /*初始化节点*/
    if (newnode)
    {
        newnode->ndata = *data;
        newnode->ltree = NULL;
        newnode->rtree = NULL;
    }

    /*返回新节点*/
    return newnode;
}

void DeleteNode(TreeNode *node)
{
    free(node);
}

bool AddNode(BinaryTree *tree, NodeType *data)
{
    TreeNode *newnode = CreateNode(data);
    if (*tree == NULL)
        *tree = newnode;
    else
        return false;
    return true;
}

void InsertNode(BinaryTree *tree, TreeNode *node)
{
    if ((*tree)->ndata > node->ndata)
    {

    }
}