#ifndef SET_CW_DEF
#define SET_CW_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  =============================   */
void bitPatt(Set s) {
    int offset=sizeof(s)*8-1;
    for(; offset>=0; offset--) {
        printf("%d ", s>>offset&1);
    }
    puts("");
}
/*  =============================   */
void insertEl(int n, Set *s) {
    *s|=1<<n;
}

void deleteEl(int n, Set *s) {
    *s&=~(1<<n);
}
/*  =============================   */
bool isMember(int n, Set s) {
    return s>>n&1==1;
}
/*  =============================   */

#endif