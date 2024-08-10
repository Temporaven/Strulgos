#ifndef UID_A_PROTO
#define UID_A_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int Set[SIZE];

/*  =========================   */
Set *uniSet(Set a, Set b);
Set *intSet(Set a, Set b);
Set *difSet(Set a, Set b);
/*  =========================   */
bool isMember(int n, Set s);
void display(Set s);
/*  =========================   */

#endif