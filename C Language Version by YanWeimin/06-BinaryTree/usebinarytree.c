#include <stdio.h>
#include <stdbool.h>
#include "binarytree.h"

int main(void)
{
    BinaryTree myTree;
    NodeType myNode = 1;

    InitTree(&myTree);
    AddNode(&myTree, &myNode);
    myNode = 0;
    AddNode(&myTree, &myNode);
    myNode = 2;
    AddNode(&myTree, &myNode);
    printf("%d\n", myTree->ltree->ndata);
    printf("%d\n", myTree->ndata);
    printf("%d\n", myTree->rtree->ndata);
    DestoryTree(&myTree);

    return 0;
}