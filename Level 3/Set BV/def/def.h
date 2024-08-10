#ifndef SET_BV_DEF
#define SET_BV_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  ============================    */
Set *uni(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x;
        for(x=0; x<SIZE; x++) {
            (*newSet)[x]=a[x]|b[x];
        }
    }
    return newSet;
}

Set *inter(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x;
        for(x=0; x<SIZE; x++) {
            (*newSet)[x]=a[x]&b[x];
        }
    }
    return newSet;
}

Set *diff(Set a, Set b) {
    Set *newSet=(Set*)calloc(1, sizeof(Set));
    if(newSet!=NULL) {
        int x;
        for(x=0; x<SIZE; x++) {
            (*newSet)[x]=a[x]&~b[x];
        }
        Set *newtwo=(Set*)calloc(1, sizeof(Set));
        if(newtwo!=NULL) {
            int x;
            for(x=0; x<SIZE; x++) {
                (*newtwo)[x]=b[x]&~a[x];
            }
        }
        for(x=0; x<SIZE; x++) {
            (*newSet)[x]=(*newSet)[x]|(*newtwo)[x];
        }
        free(newtwo);
    }
    return newSet;
}
/*  ============================    */
bool isMember(int n, Set s) {
    return s[n]==1;
}
/*  ============================    */
void display(Set s) {
    int x;
    for(x=0; x<SIZE; x++) {
        printf("%d ", s[x]);
    }
    puts("");
}
/*  ============================    */

#endif