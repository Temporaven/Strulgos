#ifndef UID_A_DEF
#define UID_A_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  =========================================   */
Set *uniSet(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x, y, checker = 0;
        for(x=0, y=0; x<SIZE&&(checker==0||a[x]!=0); x++) {
            (*newSet)[y++]=a[x];
            if(a[x]==0&&checker==0) {
                checker = 1;
            }
        }
        for(x=0; x<SIZE; x++) {
            if(!isMember(b[x], *newSet)) {
                (*newSet)[y++]=b[x];
            }
        }
    }
    return newSet;
}

Set *intSet(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x, y;
        for(x=0, y=0; x<SIZE; x++) {
            if(isMember(a[x], b)) {
                (*newSet)[y++]=a[x];
            }
        }
    }
    return newSet;
}

Set *difSet(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x, y;
        for(x=0, y=0; x<SIZE; x++) {
            if(!isMember(a[x], b)) {
                (*newSet)[y++]=a[x];
            }
        }
        for(x=0; x<SIZE; x++) {
            if(!isMember(b[x], a)) {
                (*newSet)[y++]=b[x];
            }
        }
    }
    return newSet;
}
/*  =========================================   */
bool isMember(int n, Set s) {
    int x;
    for(x=0; x<SIZE&&s[x]!=n; x++){}
    return x<SIZE;
}

void display(Set s) {
    int x;
    for(x=0; x<SIZE; x++) {
        printf("%d ", s[x]);
    }
    puts("");
}
/*  =========================================   */

#endif