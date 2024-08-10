#include "def/def.h"

int main(void) {
    Heap H;
    Data D={5, 2, 4, 1, 6, 7, 9, 21, 69};
    insertAll(D, &H);
    puts("Min Heap:");
    displayHeap(H);

    return 0;
}