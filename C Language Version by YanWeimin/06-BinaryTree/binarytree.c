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
    if ((*tree)->ltree) //处理左子树
        DestoryTree(&((*tree)->ltree));
    if ((*tree)->rtree) //处理右子树
        DestoryTree(&((*tree)->rtree));
    free(*tree); //释放节点内存
}

TreeNode *CreateNode(NodeType *data)
{
    /*分配动态内存，创建新节点*/
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));

    /*初始化节点*/
    if (newnode)
    {
        newnode->ndata = *data; //拷贝数据
        newnode->ltree = NULL;  //设置左子树为空
        newnode->rtree = NULL;  //设置右子树为空
    }

    /*返回新节点*/
    return newnode;
}

void DeleteNode(TreeNode *node)
{
    /*释放节点内存*/
    free(node);
}

bool AddNode(BinaryTree *tree, NodeType *data)
{
    TreeNode *newnode = CreateNode(data); //创建新节点
    InsertNode(tree, newnode);            //将新节点插入树中
    return true;
}

void InsertNode(BinaryTree *tree, TreeNode *node)
{
    /*先序遍历*/
    if (*tree == NULL) //将新节点插入到树中
        *tree = node;
    else if ((*tree)->ndata > node->ndata) //处理左子树
        InsertNode(&((*tree)->ltree), node);
    else //树立右子树
        InsertNode(&((*tree)->rtree), node);
}

bool SearchNode(BinaryTree *tree, NodeType *data)
{
}