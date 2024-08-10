#ifndef UID_LL_PROTO
#define UID_LL_PROTO

#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int num;
    struct node *link;
}*Set;

/*  ==============================  */
void init(Set *S);
void insertLast(int n, Set *S);
void display(Set S);
/*  ==============================  */
Set uniSet(Set a, Set b);
Set intSet(Set a, Set b);
Set difSet(Set a, Set b);
/*  ==============================  */
bool isMember(int n, Set S);
/*  ==============================  */

#endif