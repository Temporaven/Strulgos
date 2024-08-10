#ifndef MIN_INSALL_PROTO
#define MIN_INSALL_PROTO

#define SIZE 9
typedef int Data[SIZE];
typedef struct {
    int elem[SIZE];
    int lastNdx;
}Heap;

/*  =============================== */
void insertAll(Data d, Heap *h);
void swap(int *a, int *b);
/*  =============================== */
void displayHeap(Heap h);
/*  =============================== */

#endif