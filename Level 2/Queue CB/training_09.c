#include "def/def.h"

int main(void) {
    queue Q;
    init(&Q);
    Words wdata={"Hello", "there", "world,"};
    populate(wdata, &Q);
    display(&Q);

    insertSorted("unbelievable", &Q);
    insertSorted("zeheheheha!", &Q);
    insertFront("Ah,", &Q);
    display(&Q);

    dequeue(&Q);
    deleteWord("there", &Q);
    deleteRear(&Q);
    display(&Q);

    return 0;
}