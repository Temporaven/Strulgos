#ifndef SET_CW_PROTO
#define SET_CW_PROTO

#include <stdbool.h>

typedef char Set;

/*  ============================    */
void bitPatt(Set s);
/*  ============================    */
void insertEl(int n, Set *s);
void deleteEl(int n, Set *s);
/*  ============================    */
bool isMember(int n, Set s);
/*  ============================    */

#endif