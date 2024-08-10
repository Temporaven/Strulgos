#ifndef MIN_INSALL_DEF
#define MIN_INSALL_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  =============================== */
void insertAll(Data d, Heap *h) {
    h->lastNdx=-1;
    int x, y;
    for(x=0; x<SIZE; ++x, h->lastNdx++) {
        h->elem[x]=d[x];
        for(y=x; y>0&&h->elem[y]<h->elem[(y-1)/2]; y=(y-1)/2) {
            swap(&h->elem[(y-1)/2], &h->elem[y]);
        }
    }
}

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*  =============================== */
void displayHeap(Heap h) {
    int x;
    printf("[");
    for(x=0; x<=h.lastNdx; ++x) {
        (x<h.lastNdx)?printf("%d, ", h.elem[x]):printf("%d]", h.elem[x]);
    }
    printf("\n\n");
}
/*  =============================== */

#endif