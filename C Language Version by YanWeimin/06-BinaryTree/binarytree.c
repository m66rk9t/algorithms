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
    /*后序遍历树，释放节点*/
    PostOrder(tree, FreeNode);
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

// void DeleteNode(TreeNode *node)
// {

// }

void FreeNode(TreeNode *node)
{
    /*释放节点内存*/
    free(node);
}

bool AddNode(BinaryTree *tree, NodeType *data)
{
    TreeNode *newnode = CreateNode(data); //创建新节点

    if (!newnode) //创建节点失败
        return false;

    if (SearchNode(tree, &(newnode->ndata))) //查找节点是否存在于树中
        return false;

    InsertNode(tree, newnode); //将新节点插入树中

    /*添加成功*/
    return true;
}

void InsertNode(BinaryTree *tree, TreeNode *node)
{
    /*先序遍历*/
    if (*tree == NULL) //将新节点插入到树中
        *tree = node;
    else if ((*tree)->ndata > node->ndata) //处理左子树
        InsertNode(&((*tree)->ltree), node);
    else //处理右子树
        InsertNode(&((*tree)->rtree), node);
}

bool SearchNode(BinaryTree *tree, NodeType *data)
{
    /*node指向二叉树根节点*/
    TreeNode *node = *tree;

    while (node)
    {
        if (node->ndata > *data) //处理左子树
            node = node->ltree;
        else if (node->ndata < *data) //处理右子树
            node = node->rtree;
        else //查找成功
            return true;
    }

    /*查找失败*/
    return false;
}

void VisitNode(TreeNode *node, void (*pfun)(TreeNode *pnode))
{
    /*访问节点*/
    pfun(node);
}

void PrintNodeData(TreeNode *node)
{
    /*打印节点数据*/
    printf("%-3d ", node->ndata);
}

void PreOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*先序遍历*/
    if (*tree)
    {
        VisitNode(*tree, pfun);
        InOrder(&((*tree)->ltree), pfun);
        InOrder(&((*tree)->rtree), pfun);
    }
}

void InOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*中序遍历*/
    if (*tree)
    {
        InOrder(&((*tree)->ltree), pfun);
        VisitNode(*tree, pfun);
        InOrder(&((*tree)->rtree), pfun);
    }
}

void PostOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*后序遍历*/
    if (*tree)
    {
        InOrder(&((*tree)->ltree), pfun);
        InOrder(&((*tree)->rtree), pfun);
        VisitNode(*tree, pfun);
    }
}
