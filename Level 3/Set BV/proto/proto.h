#ifndef SET_BV_PROTO
#define SET_BV_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int Set[SIZE];

/*  =========================== */
Set *uni(Set a, Set b);
Set *inter(Set a, Set b);
Set *diff(Set a, Set b);
/*  =========================== */
bool isMember(int n, Set s);
/*  =========================== */
void display(Set s);
/*  =========================== */

#endif