/****************************************************************************
*   DISCLAIMER: This is literally the same code in Bryan Sanchez's repo.    *
*****************************************************************************/
#ifndef KRUSKAL_DEF
#define KRUSKAL_DEF

#include "../heap/hcode.h"
#include <limits.h>

#define MAT_MAX 7
#define COMP_MAX 7
#define INF INT_MAX

typedef int Matrix[MAT_MAX][MAT_MAX];

typedef struct {
    edgeType pathRec[PATH_MAX];
    int edgeCount;
    int totalWeight;
}path;

// Prototypes
path kruskall(Matrix m);
void initPath(path *pk);
void insertToPath(int tail, int head, int weight, path *pk);
void displayMatrix(Matrix m);
void displayPath(path pk);

// Definitons
path kruskall(Matrix m) {
    int components[COMP_MAX] = {0}, from, to;
    edgeType data;
    Heap hp;
    initHeap(&hp);
    path krusk;
    initPath(&krusk);

    // Values are components that vertex is part of
    // Initially, each vertex is its own component
    for (from = 0; from < COMP_MAX; from++) {
        components[from] = from;
    }

    // Build min heap containing all edges
    for (from = 0; from < MAT_MAX; from++) {
        for (to = 0; to < MAT_MAX; to++) {
            if (m[from][to] != INF && from < to) {
                data.weight = m[from][to];
                data.from = from;
                data.to = to;
                insertAll(data, &hp);
            }

        }
    }

    int compNum;
    // Stop when number of components is 1
    for (compNum = COMP_MAX, data = deleteMin(&hp); compNum > 1; data = deleteMin(&hp)) {
        from = data.from;
        to = data.to;

        // Edge joins two vertices from different components
        if (components[from] != components[to]) {
            insertToPath(from, to, data.weight, &krusk);

            // Merge `to` component vertices into the
            // `from` component
            int ctr, oldComp = components[to];
            for (ctr = 0; ctr < COMP_MAX; ctr++) {
                if (components[ctr] == oldComp) {
                    components[ctr] = components[from];
                }
            }
            --compNum;
        }
    }
    return krusk;
}

void initPath(path *pk) {
    pk->edgeCount=pk->totalWeight=0;
}

void insertToPath(int tail, int head, int wt, path *pk) {
    if(pk->edgeCount<PATH_MAX) {
        pk->pathRec[pk->edgeCount].from=tail;
        pk->pathRec[pk->edgeCount].to=head;
        pk->pathRec[pk->edgeCount].weight=wt;
        pk->totalWeight+=wt;
        ++pk->edgeCount;
    }
}

void displayMatrix(Matrix m) {
    printf("Matrix ::");
    printf("\n---------\n");
    int x, y;
    for(x=0; x<MAT_MAX; ++x) {
        printf("\n[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%11d ", m[x][y]);
        }
        printf("]");
    }
    printf("\n\n");
}

void displayPath(path pk) {
    printf("Path ::");
    printf("\n-------\n");
    int x;
    for(x=0; x<pk.edgeCount; ++x) {
        printf("\n(%d) (%d) :: %d", pk.pathRec[x].from, pk.pathRec[x].to, pk.pathRec[x].weight);
    }
    printf("\nTotal weight: %d\n\n", pk.totalWeight);
}

#endif