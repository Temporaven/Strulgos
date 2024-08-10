#include "def/def.h"

int main(void) {
    Set a={5, 0, 2, 9, 3}, b={7, 1, 0, 3, 8};
    puts("Union:");
    display(*uniSet(a, b));

    puts("Intersection:");
    display(*intSet(a, b));

    puts("Difference:");
    display(*difSet(a, b));

    return 0;
}