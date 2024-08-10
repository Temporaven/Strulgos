#ifndef UID_CB_DEF
#define UID_CB_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  =============================== */
Set create() {
    Set newSet;
    newSet.stIdx=-1;
    initVH(&newSet.VHeap);
    return newSet;
}

void initVH(virtHeap *VH) {
    int x;
    for(x=0; x<VHS; x++) {
        VH->vnode[x].link=(x<VHS-1)?x+1:-1;
    }
    VH->avail=0;
}

void display(Set S) {
    int trav;
    for(trav=S.stIdx; trav!=-1; trav=S.VHeap.vnode[trav].link) {
        printf("%d ", S.VHeap.vnode[trav].num);
    }
    puts("");
}
/*  =============================== */
int allocVH(virtHeap *VH) {
    int rdx=VH->avail;
    if(rdx!=-1) {
        VH->avail=VH->vnode[rdx].link;
    }
    return rdx;
}

void insertLast(int n, Set *S) {
    int ndx=allocVH(&S->VHeap);
    if(ndx!=-1) {
        int *trav;
        for(trav=&S->stIdx; (*trav)!=-1; trav=&(S->VHeap.vnode[*trav].link)){}
        S->VHeap.vnode[ndx].num=n;
        S->VHeap.vnode[ndx].link=-1;
        (*trav)=ndx;
    }
}
/*  =============================== */
Set uniSet(Set A, Set B) {
    Set newSet=create();
    int trav;
    for(trav=A.stIdx; trav!=-1; trav=A.VHeap.vnode[trav].link) {
        insertLast(A.VHeap.vnode[trav].num, &newSet);
    }
    for(trav=B.stIdx; trav!=-1; trav=B.VHeap.vnode[trav].link) {
        if(!isMember(B.VHeap.vnode[trav].num, newSet)) {
            insertLast(B.VHeap.vnode[trav].num, &newSet);
        }
    }
    return newSet;
}

Set intSet(Set A, Set B) {
    Set newSet=create();
    int trav;
    for(trav=A.stIdx; trav!=-1; trav=A.VHeap.vnode[trav].link) {
        if(isMember(A.VHeap.vnode[trav].num, B)) {
            insertLast(A.VHeap.vnode[trav].num, &newSet);
        }
    }
    return newSet;
}

Set difSet(Set A, Set B) {
    Set newSet=create();
    int trav;
    for(trav=A.stIdx; trav!=-1; trav=A.VHeap.vnode[trav].link) {
        if(!isMember(A.VHeap.vnode[trav].num, B)) {
            insertLast(A.VHeap.vnode[trav].num, &newSet);
        }
    }
    for(trav=B.stIdx; trav!=-1; trav=B.VHeap.vnode[trav].link) {
        if(!isMember(B.VHeap.vnode[trav].num, A)) {
            insertLast(B.VHeap.vnode[trav].num, &newSet);
        }
    }
    return newSet;
}
/*  =============================== */
bool isMember(int n, Set S) {
    int trav;
    for(trav=S.stIdx; trav!=-1&&S.VHeap.vnode[trav].num!=n; trav=S.VHeap.vnode[trav].link){}
    return trav!=-1;
}
/*  =============================== */

#endif