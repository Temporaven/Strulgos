#ifndef MAX_HEAPIFY_DEF
#define MAX_HEAPIFY_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  ==============================  */
void displayHeap(Heap h) {
    int x;
    for(x=0; x<=h.lastNdx; ++x) {
        (x<h.lastNdx)?printf("%d, ", h.elem[x]):printf("%d", h.elem[x]);
    }
    printf("\n\n");
}
/*  ==============================  */
void heapSort(Heap *h) {
    int x, origNdx=h->lastNdx;
    for(x=(h->lastNdx/2)-1; x>=0; --x) {
        heapify(h, x);
    }
    puts("Max Heap:");
    displayHeap(*h);

    while(h->lastNdx>0) {
        deleteMax(h);
    }
    h->lastNdx=origNdx;
}

void heapify(Heap *h, int ndx) {
    int pn=ndx, lar=pn, cn=(2*pn)+1;
    if(cn<=h->lastNdx&&h->elem[cn]>h->elem[lar]) {
        lar=cn;
    }
    if(cn+1<=h->lastNdx&&h->elem[cn+1]>h->elem[lar]) {
        lar=cn+1;
    }
    if(pn!=lar) {
        swap(&h->elem[pn], &h->elem[lar]);
        heapify(h, lar);
    }
}

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void deleteMax(Heap *h) {
    swap(&h->elem[0], &h->elem[h->lastNdx]);
    h->lastNdx--;
    heapify(h, 0);
}
/*  ==============================  */

#endif