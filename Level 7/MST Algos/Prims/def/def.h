#ifndef PRIM_DEF
#define PRIM_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdbool.h>

path prims(int src, Matrix m);
void initPath(path *pt);
void insertToPath(int tl, int hd, int wt, path *sp);
void displayMat(Matrix m);
void displayPath(path pt);

path prims(int src, Matrix m) {
    bool visited[ARR_MAX]={0};
    path primo;
    initPath(&primo);

    // Begin
    /****************************************************************************
    *   TERMINOLOGIES:                                                          *
    *       ctr - runs until the maximum no. of edges can be found              *
    *       x - an initializer and tail ctr                                     *
    *       y - head ctr initializer                                            *
    *       tailHolder - holds the next tail that we're considering to visit    *
    *       headHolder - holds the next head that we're considering to visit    *
    *       min - smallest weight found to be added to the official path        *
    *****************************************************************************/
    int ctr, x, y, tailHolder, headHolder, min;
    for(ctr=0, tailHolder=src, headHolder=src, min=INF; ctr<MAT_MAX-1; ++ctr, min=INF, tailHolder=headHolder, headHolder=src) {
        visited[tailHolder]=1;
        for(x=0; x<MAT_MAX; ++x) {
            // we only check the visited vertices and their adj vertices
            if(visited[x]==1) {
                for(y=0; y<MAT_MAX; ++y) {
                    // TIP: Always consider the possibility of an edge having an INF value. Basically, a node almost always has a nonadjacent vertex (other than itself)
                    // if there's a cheaper weight, update the weight accordingly
                    /************************************************************************************************************************
                    *   1.) if there exists an edge, 2.) the current cost is smaller than the minimum cost found out of all visited nodes,  *
                    *   3.) and that this next adj vertex is unvisited, consider this adj vertex the next node to visit and update min      *
                    *************************************************************************************************************************/
                    if(m[x][y]!=INF&&m[x][y]<min&&visited[y]==0) {
                        min=m[x][y], tailHolder=x, headHolder=y;
                    }
                }
            }
        }
        // only insert if min is not an INF value and that the current vertex doesn't form a cycle
        if(min!=INF&&headHolder!=src) {
            insertToPath(tailHolder, headHolder, min, &primo);
        }
    }
    return primo;
}

void initPath(path *pt) {
    pt->edgeCount=pt->totalWeight=0;
}

void insertToPath(int tl, int hd, int wt, path *sp) {
    if(sp->edgeCount<ARR_MAX-1) {
        switch(tl) {
            case 0: sp->edgeInfo[sp->edgeCount].tail='A'; break;
            case 1: sp->edgeInfo[sp->edgeCount].tail='B'; break;
            case 2: sp->edgeInfo[sp->edgeCount].tail='C'; break;
            case 3: sp->edgeInfo[sp->edgeCount].tail='D'; break;
            case 4: sp->edgeInfo[sp->edgeCount].tail='E'; break;
            case 5: sp->edgeInfo[sp->edgeCount].tail='F'; break;
            case 6: sp->edgeInfo[sp->edgeCount].tail='G'; break;
            default: break;
        }
        switch(hd) {
            case 0: sp->edgeInfo[sp->edgeCount].head='A'; break;
            case 1: sp->edgeInfo[sp->edgeCount].head='B'; break;
            case 2: sp->edgeInfo[sp->edgeCount].head='C'; break;
            case 3: sp->edgeInfo[sp->edgeCount].head='D'; break;
            case 4: sp->edgeInfo[sp->edgeCount].head='E'; break;
            case 5: sp->edgeInfo[sp->edgeCount].head='F'; break;
            case 6: sp->edgeInfo[sp->edgeCount].head='G'; break;
            default: break;
        }
        sp->edgeInfo[sp->edgeCount].weight=wt;
        sp->totalWeight+=wt;
        ++sp->edgeCount;
    }
}

void displayMat(Matrix m) {
    printf("\nMatrix ::");
    printf("\n---------\n");
    int x, y;
    for(x=0; x<MAT_MAX; ++x) {
        printf("[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%11d ", m[x][y]);
        }
        printf("]\n");
    }
    puts("");
}

void displayPath(path pt) {
    printf("\nPath ::");
    printf("\n-------");
    int x;
    for(x=0; x<pt.edgeCount; ++x) {
        printf("\n(%c) (%c) :: %d", pt.edgeInfo[x].tail, pt.edgeInfo[x].head, pt.edgeInfo[x].weight);
    }
    printf("\n\nTotal weight: %d\n\n", pt.totalWeight);
}

#endif