#ifndef UID_CB_PROTO
#define UID_CB_PROTO

#include <stdbool.h>

#define VHS 10
typedef struct {
    int num;
    int link;
}nodes;
typedef struct {
    nodes vnode[VHS];
    int avail;
}virtHeap;
typedef struct {
    int stIdx;
    virtHeap VHeap;
}Set;

/*  ==============================  */
Set create();
void initVH(virtHeap *VH);
void display(Set S);
/*  ==============================  */
int allocVH(virtHeap *VH);
void insertLast(int n, Set *S);
/*  ==============================  */
Set uniSet(Set A, Set B);
Set intSet(Set A, Set B);
Set difSet(Set A, Set B);
/*  ==============================  */
bool isMember(int n, Set S);
/*  ==============================  */

#endif