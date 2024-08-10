#ifndef WARSHALL_DEF
#define WARSHALL_DEF

#include "../proto/proto.h"
#include <stdio.h>

void warshallsAlgo(labeledAdjMatrix AM, warshallMatrix WM) {
    int x, y, z;
    for(x=0; x<MAT_MAX; ++x) {
        for(y=0; y<MAT_MAX; ++y) {
            WM[x][y]=(AM[x][y]==INF)?0:1;
        }
    }

    // Begin
    for(x=0; x<MAT_MAX; ++x) {
        for(y=0; y<MAT_MAX; ++y) {
            for(z=0; z<MAT_MAX; ++z) {
                WM[y][z]=(WM[y][x]==1&&WM[x][z]==1)?WM[y][x]&WM[x][z]:WM[y][z];
            }
        }
    }
}

void displayMatrix(labeledAdjMatrix AM) {
    printf("\n-------MATRIX-------");
    int x, y;
    for(x=0; x<MAT_MAX; ++x) {
        printf("\n[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%11d ", AM[x][y]);
        }
        printf("]");
    }
    printf("\n\n");
}

void displayWMatrix(warshallMatrix WM) {
    printf("\n-------WARSHALL MATRIX-------");
    int x, y;
    for(x=0; x<MAT_MAX; ++x) {
        printf("\n[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%11d ", WM[x][y]);
        }
        printf("]");
    }
    printf("\n\n");
}

#endif