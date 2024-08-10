#include "def/def.h"

int main(void) {
    stack S;
    init(&S);
    Words wData={"Hello", "there", "world,"};
    populate(wData, &S);
    display(&S);

    insertSorted("unbelievable", &S);
    insertSorted("zeheheheha!", &S);
    insertBott("Ah,", &S);
    display(&S);

    pop(&S);
    deleteWord("there", &S);
    deleteBott(&S);
    display(&S);

    return 0;
}