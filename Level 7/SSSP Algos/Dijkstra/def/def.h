#ifndef DIJKSTRA_DEF
#define DIJKSTRA_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdbool.h>

path dijkstra(int src, Matrix m) {
    bool visited[ARR_MAX]={0};
    int cost[ARR_MAX], x;
    for(x=0; x<ARR_MAX; ++x) {
        cost[x]=(x==src)?0:INF;
    }
    path dj;
    initPath(&dj);

    // Begin
    /********************************************************************************************
    *   TERMINOLOGIES:                                                                          *
    *       currTail - current tail we're in                                                    *
    *       nextTail - next tail we're considering as the final adj node                        *
    *       head - checks the adj vertices and is used to check its cost                        *
    *       currCost - if ever there's an adj vertex, then it's the current cost of that vertex *
    *       minCost - the smallest minimum cost found out of all the adj vertices               *
    *       infChecker - checks if the current node doesn't have any adj vertices               *
    *       oldTail - holds the previous tail visited                                           *
    ********************************************************************************************/
    int currTail, nextTail, head, currCost, minCost, infChecker, oldTail;
    for(currTail=src, nextTail=src, minCost=INF; visited[currTail]!=1; currTail=nextTail, nextTail=src, minCost=INF) {
        visited[currTail]=1;
        for(head=0, currCost=INF, infChecker=0; head<MAT_MAX; ++head, currCost=INF) {
            if(m[currTail][head]!=INF) {
                currCost=cost[currTail]+m[currTail][head];
            } else {
                // if no adj vertices, the next adj vertice must be from the previous tail (if it's not the last vertex)
                // basically, if n nodes & infChecker==n, there is no adj vertex avail.
                ++infChecker;
            }
            // If the new current weight added with the current weight of the adj vertex is cheaper than the initial weight at that paritcular adj vertex, then update the initial weight
            if(currCost<cost[head]) {
                cost[head]=currCost;
            }
            // Check the cheapest path among all adj vertices and consider this as the next adj node to be added to the path
            if(cost[head]<minCost&&visited[head]==0) {
                minCost=cost[head], nextTail=head;
            }
        }
        // checks if the current node that doesn't lead to a dead end
        if(minCost!=INF&&nextTail!=src) {
            if(infChecker<MAT_MAX) {
                // update the oldTail to point to the newTail and insert as you normally would
                oldTail=currTail;
                insertToPath(currTail, nextTail, minCost, &dj);
            } else {
                // the tail that holds the next adj vertex must be the previous tail and not the current tail since there's no adj vertices at the current tail
                insertToPath(oldTail, nextTail, minCost, &dj);
            }
        }
    }
    return dj;
}

void initPath(path *sp) {
    sp->edgeCount=sp->totalWeight=0;
}

void insertToPath(int tl, int hd, int wt, path *sp) {
    if(sp->edgeCount<ARR_MAX-1) {
        switch(tl) {
            case 0: sp->EI[sp->edgeCount].tail='A'; break;
            case 1: sp->EI[sp->edgeCount].tail='B'; break;
            case 2: sp->EI[sp->edgeCount].tail='C'; break;
            case 3: sp->EI[sp->edgeCount].tail='D'; break;
            case 4: sp->EI[sp->edgeCount].tail='E'; break;
            default: break;
        }
        switch(hd) {
            case 0: sp->EI[sp->edgeCount].head='A'; break;
            case 1: sp->EI[sp->edgeCount].head='B'; break;
            case 2: sp->EI[sp->edgeCount].head='C'; break;
            case 3: sp->EI[sp->edgeCount].head='D'; break;
            case 4: sp->EI[sp->edgeCount].head='E'; break;
            default: break;
        }
        sp->EI[sp->edgeCount].weight=wt;
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

void displayPath(path sp) {
    printf("\nPath ::");
    printf("\n-------");
    int x;
    for(x=0; x<sp.edgeCount; ++x) {
        printf("\n(%c) (%c) :: %d", sp.EI[x].tail, sp.EI[x].head, sp.EI[x].weight);
    }
    printf("\n\nTotal weight: %d\n\n", sp.totalWeight);
}

#endif