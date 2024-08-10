#include "def/def.h"

int main(void) {
    Dictionary D;
    init(D);
    Set S={10, 33, 25, 68, 91, 45, 77, 0, 89};
    populateDict(S, D);
    insertSorted(2, D);
    insertSorted(3, D);
    insertSorted(82, D);
    insertSorted(33, D);
    display(D);

    puts("");
    deleteEl(10, D);
    display(D);

    return 0;
}