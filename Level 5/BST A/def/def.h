#ifndef BST_A_DEF
#define BST_A_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  ============================    */
void init(Tree T) {
    int x, y;
    for(x=0; x<RSIZE; ++x) {
        for(y=0; y<CSIZE; ++y) {
            T[x][y]=EMPTY;
        }
    }
}

void populate(Data D, Tree T) {
    int x, y, *trav;
    for(x=0; x<CSIZE; ++x) {
        T[0][x]=D[x];
        if(x>0) {
            for(y=0, trav=&T[0][0]; *trav!=-1; ) {
                trav=(T[0][x]<T[0][y])?&T[1][y]:&T[2][y];
                y=*trav;
            }
            *trav=x;
        }
    }
}

void displayData(Tree T) {
    int x, y;
    for(x=0; x<RSIZE; ++x) {
        printf("[%d]: ", x);
        for(y=0; y<CSIZE; ++y) {
            printf("%2d ", T[x][y]);
        }
        puts("");
    }
    puts("");
}
/*  ============================    */
void preOrder(Tree T, int node) {
    if(node!=-1) {
        printf("%d ", T[0][node]);
        preOrder(T, T[1][node]);
        preOrder(T, T[2][node]);
    }
}

void inOrder(Tree T, int node) {
    if(node!=-1) {
        inOrder(T, T[1][node]);
        printf("%d ", T[0][node]);
        inOrder(T, T[2][node]);
    }
}

void postOrder(Tree T, int node) {
    if(node!=-1) {
        postOrder(T, T[1][node]);
        postOrder(T, T[2][node]);
        printf("%d ", T[0][node]);
    }
}
/*  ============================    */

#endif