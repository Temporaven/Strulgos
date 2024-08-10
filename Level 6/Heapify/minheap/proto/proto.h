#ifndef MIN_HEAPIFY_PROTO
#define MIN_HEAPIFY_PROTO

#define SIZE 9
typedef struct {
    int elem[SIZE];
    int lastNdx;
}Heap;

/*  ==============================  */
void displayHeap(Heap h);
/*  ==============================  */
void heapSort(Heap *h);
void heapify(Heap *h, int ndx);
void swap(int *a, int *b);
void deleteMin(Heap *h);
/*  ==============================  */

#endif