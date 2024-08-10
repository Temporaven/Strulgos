#ifndef DFS_DEF
#define DFS_DEF

#include "../stack/scode.h"
#include <stdio.h>
#include <stdlib.h>

#define MAT_MAX 5
#define ARR_MAX 5
typedef int Matrix[MAT_MAX][MAT_MAX];

int *DFS(int src, Matrix m) {
    int *res=(int*)calloc(ARR_MAX, sizeof(int));
    int *visited=(int*)calloc(ARR_MAX, sizeof(int));
    if(res!=NULL&&visited!=NULL) {
        Stack nodeHolder;
        initialize(&nodeHolder);

        int node, ctr, x;
        for(node=src, ctr=0, push(node, &nodeHolder); !isEmpty(nodeHolder)&&ctr<ARR_MAX; node=top(nodeHolder)) {
            res[ctr++]=node;
            visited[node]=1;
            pop(&nodeHolder);
            for(x=MAT_MAX-1; x>-1; --x) {
                if(m[node][x]==1&&visited[x]==0) {
                    push(x, &nodeHolder);
                }
            }
        }
    }
    return res;
}

void displayMat(Matrix m) {
    int x, y;
    printf("%50s", "THE MATRIX ::");
    printf("\n%50s", "-------------");
    for(x=0; x<MAT_MAX; ++x) {
        printf("\n[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%15d ", m[x][y]);
        }
        printf("]");
    }
    printf("\n\n");
}

void displayArr(int *r) {
    int x;
    printf("%50s", "THE RESULT ::");
    printf("\n%50s", "-------------");
    printf("\n[ ");
    for(x=0; x<ARR_MAX; ++x) {
        printf("%15d ", r[x]);
    }
    printf("]\n\n");
}

#endif