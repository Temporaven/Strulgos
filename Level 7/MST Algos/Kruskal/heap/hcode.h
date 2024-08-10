#ifndef HEAP_DEF
#define HEAP_DEF

#include <stdio.h>

#define HEAP_MAX 36
#define PATH_MAX 6

typedef struct {
    int from;
    int to;
    int weight;
}edgeType;

typedef struct {
    edgeType edges[HEAP_MAX];
    int lastNdx;
}Heap;

// Prototypes
void initHeap(Heap *h);
void insertAll(edgeType data, Heap *h);
edgeType deleteMin(Heap *h);
void heapify(int src, Heap *h);

// Definitions
void initHeap(Heap *h) {
    h->lastNdx = -1;
}

void insertAll(edgeType data, Heap *h) {
    if (h->lastNdx >= HEAP_MAX - 1) {
        printf("HEAP IS FULL\n");
    } else {
        h->edges[++h->lastNdx]=data;
        int idx;

        for (idx = h->lastNdx; idx > 0 && data.weight < h->edges[(idx - 1) / 2].weight; idx = (idx - 1) / 2) {
            edgeType temp = h->edges[idx];
            h->edges[idx] = h->edges[(idx - 1) / 2];
            h->edges[(idx - 1) / 2] = temp;
        }
    }
}

edgeType deleteMin(Heap *h) {
    edgeType res={-1, -1, 0};
    if (h->lastNdx > -1) {
        res = h->edges[0];
        h->edges[0] = h->edges[h->lastNdx];
        h->edges[h->lastNdx--] = res;
        heapify(0, h);
    }

    return res;
}

void heapify(int src, Heap *h) {
    int left = 2 * src + 1;
    int right = 2 * src + 2;
    int smallest = src;

    if (left <= h->lastNdx && h->edges[left].weight < h->edges[smallest].weight) {
        smallest = left;
    }

    if (right <= h->lastNdx && h->edges[right].weight < h->edges[smallest].weight) {
        smallest = right;
    }

    if (smallest != src) {
        edgeType temp = h->edges[src];
        h->edges[src] = h->edges[smallest];
        h->edges[smallest] = temp;
        heapify(smallest, h);
    }
}

#endif