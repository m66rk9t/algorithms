/*二叉树定义*/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdbool.h>

/*类型定义*/
typedef int NodeType;
typedef struct binarytree
{
    NodeType ndata;
    struct binarytree *ltree;
    struct binarytree *rtree;
} TreeNode, *BinaryTree;

/*函数原型*/
/*操作：初始化二叉树*/
/*前置条件：*tree指向一个未初始化的二叉树*/
/*后置条件：*tree指向一个已初始化的空二叉树*/
void InitTree(BinaryTree *tree);
/*操作：销毁二叉树*/
/*前置条件：*tree指向一个已初始化不为空的二叉树*/
/*后置条件：销毁*tree指向的二叉树*/
void DestoryTree(BinaryTree *tree);
/*操作：创建节点*/
/*前置条件：*data为待创建节点的数据*/
/*后置条件；创建新节点并返回该节点的地址*/
TreeNode *CreateNode(NodeType *data);
/*操作：删除节点*/
/*前置条件：node指向二叉树树中的节点*/
/*后置条件：删除node指向的节点*/
void DeleteNode(TreeNode *node);
/*操作：添加节点*/
/*前置条件：*tree指向已初始化的二叉树，*data为待添加节点的数据*/
/*后置条件：将tn指向的节点添加到*tree指向的二叉树中*/
bool AddNode(BinaryTree *tree, NodeType *data);
/*操作：插入节点*/
/*前置条件：*tree指向已初始化的二叉树，tn指向待插入的节点*/
/*后置条件：将tn指向的节点插入到*tree指向的二叉树中*/
void InsertNode(BinaryTree *tree, TreeNode *node);

#endif