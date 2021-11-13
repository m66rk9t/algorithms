/*二叉树定义*/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*类型定义*/
typedef int NodeType; //节点类型
typedef struct binarytree
{
    NodeType ndata;           //节点数据
    struct binarytree *ltree; //左子树指针
    struct binarytree *rtree; //右子树指针
} TreeNode, *BinaryTree;      //节点结构
typedef struct pair
{
    TreeNode *root; //父节点指针
    TreeNode *sub;  //子节点指针
} Pair;             //父子节点结构

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
/*操作：添加节点*/
/*前置条件：*tree指向已初始化的二叉树，*data为待添加节点的数据*/
/*后置条件：将tn指向的节点添加到*tree指向的二叉树中*/
/*         添加成功返回true，否则返回false*/
bool AddNode(BinaryTree *tree, NodeType *data);
/*操作：插入节点*/
/*前置条件：*tree指向已初始化的二叉树，node指向待插入的节点*/
/*后置条件：将node指向的节点插入到*tree指向的二叉树中*/
void InsertNode(BinaryTree *tree, TreeNode *node);
/*操作：删除节点*/
/*前置条件：*tree指向已初始化的二叉树，*data为待删除节点的数据*/
/*后置条件：删除data数据节点，删除成功返回true，否则返回false*/
bool DeleteNode(BinaryTree *tree, NodeType *data);
/*操作：重链节点*/
/*前置条件：*tree指向待删节点的位置，left指向待删节点的左节点，right指向待删节点的右节点*/
/*后置条件：合并left与right指向的子树并重新链接到*tree指向的位置*/
void RebuidTree(BinaryTree *tree, TreeNode *left, TreeNode *right);
/*操作：查找节点*/
/*前置条件：*tree指向已初始化的二叉树，*data为待查找的节点数据*/
/*后置条件：查找到以*data为数据的节点返回true，否则返回false*/
bool SearchNode(BinaryTree *tree, NodeType *data);
/*操作：定位节点*/
/*前置条件：*tree指向已初始化的二叉树，*data指向*/
/*后置条件：返回一个Pair结构，内含待查找节点及其父节点*/
Pair LocateNode(BinaryTree *tree, NodeType *data);
/*操作：释放节点*/
/*前置条件：node指向待释放的节点*/
/*后置条件：释放node指向的节点*/
void FreeNode(TreeNode *node);
/*操作：打印节点信息*/
/*前置条件：node指向树中的节点*/
/*后置条件：打印node指向的节点信息*/
void PrintNodeData(TreeNode *node);
/*操作：比较节点数据*/
/*前置条件：*first和*second为待比较的两个节点数据*/
/*后置条件：若前者大于后者返回1，小于后者返回-1，两者相等返回0*/
int CompareNodeData(NodeType *first, NodeType *second);
/*操作：访问节点*/
/*前置条件：node指向树中的节点，pfun指向作用于节点的函数*/
/*后置条件：将pfun指向的函数作用于node指向的节点*/
void VisitNode(TreeNode *node, void (*pfun)(TreeNode *pnode));
/*操作：先序遍历*/
/*前置条件：*tree指向已初始化的二叉树，pfun指向遍历函数*/
/*后置条件：将pfun指向的函数作用于树中的节点*/
void PreOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode));
/*操作：中序遍历*/
/*前置条件：*tree指向已初始化的二叉树，pfun指向遍历函数*/
/*后置条件：将pfun指向的函数作用于树中的节点*/
void InOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode));
/*操作：后序遍历*/
/*前置条件：*tree指向已初始化的二叉树，pfun指向遍历函数*/
/*后置条件：将pfun指向的函数作用于树中的节点*/
void PostOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode));

#endif