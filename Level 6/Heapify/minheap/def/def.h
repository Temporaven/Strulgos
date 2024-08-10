#ifndef MIN_HEAPIFY_DEF
#define MIN_HEAPIFY_DEF

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
    puts("Min Heap:");
    displayHeap(*h);

    while(h->lastNdx>0) {
        deleteMin(h);
    }
    h->lastNdx=origNdx;
}

void heapify(Heap *h, int ndx) {
    int pn=ndx, min=pn, cn=(2*pn)+1;
    if(cn<=h->lastNdx&&h->elem[cn]<h->elem[min]) {
        min=cn;
    }
    if(cn+1<=h->lastNdx&&h->elem[cn+1]<h->elem[min]) {
        min=cn+1;
    }
    if(pn!=min) {
        swap(&h->elem[pn], &h->elem[min]);
        heapify(h, min);
    }
}

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void deleteMin(Heap *h) {
    swap(&h->elem[0], &h->elem[h->lastNdx]);
    h->lastNdx--;
    heapify(h, 0);
}
/*  ==============================  */

#endif