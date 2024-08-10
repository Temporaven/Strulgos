#ifndef FLOYD_DEF
#define FLOYD_DEF

#include "../proto/proto.h"
#include <stdio.h>

void floydsAlgo(labeledAdjMatrix AM, floydMatrix FM) {
    int x, y, z;
    for(x=0; x<MAT_MAX; ++x) {
        for(y=0; y<MAT_MAX; ++y) {
            FM[x][y]=AM[x][y];
        }
    }
    for(x=0; x<MAT_MAX; ++x) {
        FM[x][x]=0;
    }

    // Begin
    for(x=0; x<MAT_MAX; ++x) {
        for(y=0; y<MAT_MAX; ++y) {
            for(z=0; z<MAT_MAX; ++z) {
                FM[y][z]=(FM[y][x]!=INF&&FM[x][z]!=INF&&FM[y][x]+FM[x][z]<FM[y][z])?FM[y][x]+FM[x][z]:FM[y][z];
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

void displayFMatrix(floydMatrix FM) {
    printf("\n-------FLOYD MATRIX-------");
    int x, y;
    for(x=0; x<MAT_MAX; ++x) {
        printf("\n[ ");
        for(y=0; y<MAT_MAX; ++y) {
            printf("%11d ", FM[x][y]);
        }
        printf("]");
    }
    printf("\n\n");
}

#endif