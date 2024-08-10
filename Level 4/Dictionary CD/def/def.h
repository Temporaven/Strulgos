#ifndef CD_DEF
#define CD_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  ======================================= */
void initDict(Dictionary D) {
    int x;
    for(x=0; x<SIZE; ++x) {
        D[x]=EMPTY;
    }
}
/*  ======================================= */
void populateDict(Set S, Dictionary D) {
    int x;
    for(x=0; x<SIZE; ++x) {
        insertEl(S[x], D);
    }
}

void insertEl(int el, Dictionary D) {
    if(!isMember(el, D)) {
        int ndx=hashKey(el), sig, lim;
        for(sig=0, lim=ndx; D[ndx]!=EMPTY&&sig<=1; ndx=(ndx+1)%SIZE) {
            if(lim==ndx) {
                sig++;
            }
        }
        if(sig<2) {
            D[ndx]=el;
        }
    }
}
/*  ======================================= */
bool isMember(int el, Dictionary D) {
    int ndx=hashKey(el), sig, lim;
    for(sig=0, lim=ndx; (D[ndx]!=el&&sig<=1)&&(D[ndx]!=EMPTY&&D[ndx]!=DELETED); ndx=(ndx+1)%SIZE) {
        if(lim==ndx) {
            sig++;
        }
    }
    return D[ndx]==el;
}

int hashKey(int el) {
    return el%SIZE;
}
/*  ======================================= */
void deleteEl(int el, Dictionary D) {
    int ndx=hashKey(el), sig, lim;
    for(sig=0, lim=ndx; (D[ndx]!=el&&sig<=1)&&(D[ndx]!=EMPTY&&D[ndx]!=DELETED); ndx=(ndx+1)%SIZE) {
        if(lim==ndx) {
            sig++;
        }
    }
    if(D[ndx]==el) {
        D[ndx]=DELETED;
    }
}
/*  ======================================= */
void displayDict(Dictionary D) {
    int x;
    for(x=0; x<SIZE; ++x) {
        printf("[%d]: ", x);
        printf("%d", D[x]);
        puts("");
    }
    printf("\n\n");
}
/*  ======================================= */

#endif