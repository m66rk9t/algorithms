#include <stdio.h>
#include <stdbool.h>
#include "binarytree.h"

int main(void)
{
    BinaryTree myTree;
    NodeType myNode = 1;

    InitTree(&myTree);
    AddNode(&myTree, &myNode);
    printf("%d\n", myTree->ndata);
    DestoryTree(&myTree);

    return 0;
}