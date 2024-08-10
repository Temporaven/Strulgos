#include "def/def.h"

int main(void) {
    Set S='c';
    printf("Bit pattern of %c:\n", S);
    bitPatt(S);

    insertEl(2, &S);
    printf("%d is inserted:\n", 2);
    bitPatt(S);

    deleteEl(2, &S);
    printf("%d is deleted:\n", 2);
    bitPatt(S);

    printf("Is %d part of the set?: %d\n", 7, isMember(7, S));

    return 0;
}