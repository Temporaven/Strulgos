#include "def/def.h"

int main(void) {
    Heap H={{5, 2, 4, 1, 6, 7, 9, 21, 69}, 8};
    puts("Unsorted Heap:");
    displayHeap(H);
    heapSort(&H);

    puts("Sorted Heap (asc. order):");
    displayHeap(H);

    return 0;
}