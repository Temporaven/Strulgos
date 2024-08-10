#include "def/def.h"

int main(void) {
    Set a=create(), b=create();
    insertLast(5, &a);
    insertLast(0, &a);
    insertLast(2, &a);
    insertLast(9, &a);
    insertLast(3, &a);

    insertLast(7, &b);
    insertLast(1, &b);
    insertLast(0, &b);
    insertLast(3, &b);
    insertLast(8, &b);
    puts("Set A:");
    display(a);
    puts("Set B:");
    display(b);

    puts("");
    puts("Union:");
    display(uniSet(a, b));

    puts("Intersection:");
    display(intSet(a, b));

    puts("Difference:");
    display(difSet(a, b));
    
    return 0;
}