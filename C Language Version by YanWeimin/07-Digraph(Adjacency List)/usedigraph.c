#include <stdio.h>
#include "digraph.h"

int main(void)
{
    AdjList myadj;

    InitAdjList(&myadj);
    
    printf("%d %d\n", myadj.vers, myadj.arcs);
    
    for (int i = 0; i < myadj.vers; i++)
        printf("%c", myadj.verlist[i].arctail);

    DestoryAdjList(&myadj);

    return 0;
}