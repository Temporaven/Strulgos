#include "def/def.h"

int main(void) {
    Set a={0, 1, 0, 0, 1, 0, 0, 1, 0, 1}, b={0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
    puts("Union:");
    display(*uni(a, b));

    puts("Intersection:");
    display(*inter(a, b));

    puts("Difference:");
    display(*diff(a, b));

    printf("Is %d a member of the set union?: %d\n", 1, isMember(1, *uni(a, b)));

    return 0;
}