/*二叉树实现*/
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
    if (CompareNodeData(&((*tree)->ndata), &(node->ndata)) == 1) //处理左子树
        InsertNode(&((*tree)->ltree), node);
    else if (CompareNodeData(&((*tree)->ndata), &(node->ndata)) == -1) //处理右子树
        InsertNode(&((*tree)->rtree), node);
}

bool DeleteNode(BinaryTree *tree, NodeType *data)
{
    Pair find;

    /*节点不存在*/
    if (!SearchNode(tree, data))
        return false;

    /*定位节点*/
    find = LocateNode(tree, data);

    /*重链二叉树*/
    if (!find.root) //待删节点是根节点
        RebuidTree(tree, (*tree)->ltree, (*tree)->rtree);
    else if (find.sub == find.root->ltree) //待删节点是其父节点的左节点
        RebuidTree(&(find.root->ltree), find.sub->ltree, find.sub->rtree);
    else //待删节点是其父节点的右节点
        RebuidTree(&(find.root->rtree), find.sub->ltree, find.sub->rtree);

    /*删除成功*/
    return true;
}

void RebuidTree(BinaryTree *tree, TreeNode *left, TreeNode *right)
{
    TreeNode *freenode = *tree; //临时遍历，储存待删节点的地址

    if (!left) //待删节点无左子树
        *tree = right;
    else if (!right) //待删节点无右子树
        *tree = left;
    else //待删节点有左子树和右子树
    {
        InsertNode(&left, right);
        *tree = left;
    }

    FreeNode(freenode); //释放待删节点的内存
}

bool SearchNode(BinaryTree *tree, NodeType *data)
{
    /*node指向二叉树根节点*/
    TreeNode *node = *tree;

    while (node)
    {
        if (CompareNodeData(&(node->ndata), data) == 1) //处理左子树
            node = node->ltree;
        else if (CompareNodeData(&(node->ndata), data) == -1) //处理右子树
            node = node->rtree;
        else //查找成功
            return true;
    }

    /*查找失败*/
    return false;
}

Pair LocateNode(BinaryTree *tree, NodeType *data)
{
    Pair loc;        //声明Pair结构变量，root指向待定位节点的父节点，sub指向待定位节点
    loc.root = NULL; //整棵二叉树的根节点没有父节点
    loc.sub = *tree; //指向二叉树的根节点

    /*查找节点*/
    while (loc.sub)
    {
        if (CompareNodeData(&(loc.sub->ndata), data) == 1) //处理左子树
        {
            loc.root = loc.sub;
            loc.sub = loc.sub->ltree;
        }
        else if (CompareNodeData(&(loc.sub->ndata), data) == -1) //处理右子树
        {
            loc.root = loc.sub;
            loc.sub = loc.sub->rtree;
        }
        else //查找成功
            break;
    }

    /*返回Pair结构变量*/
    return loc;
}

void FreeNode(TreeNode *node)
{
    /*释放节点内存*/
    free(node);
}

void PrintNodeData(TreeNode *node)
{
    /*打印节点数据*/
    printf("%3d ", node->ndata);
}

int CompareNodeData(NodeType *first, NodeType *second)
{
    if (*first > *second) //前者大于后者返回1
        return 1;
    else if (*first < *second) //前者小于后者返回-1
        return -1;
    else //两者相等返回0
        return 0;
}

void VisitNode(TreeNode *node, void (*pfun)(TreeNode *pnode))
{
    /*访问节点*/
    pfun(node);
}

void PreOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*先序遍历*/
    if (*tree)
    {
        VisitNode(*tree, pfun);            //访问节点
        PreOrder(&((*tree)->ltree), pfun); //遍历左子树
        PreOrder(&((*tree)->rtree), pfun); //遍历右子树
    }
}

void InOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*中序遍历*/
    if (*tree)
    {
        InOrder(&((*tree)->ltree), pfun); //遍历左子树
        VisitNode(*tree, pfun);           //访问节点
        InOrder(&((*tree)->rtree), pfun); //遍历右子树
    }
}

void PostOrder(BinaryTree *tree, void (*pfun)(TreeNode *pnode))
{
    /*后序遍历*/
    if (*tree)
    {
        PostOrder(&((*tree)->ltree), pfun); //遍历左子树
        PostOrder(&((*tree)->rtree), pfun); //遍历右子树
        VisitNode(*tree, pfun);             //访问节点
    }
}
