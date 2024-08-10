#ifndef CD_PROTO
#define CD_PROTO

#include <stdbool.h>
#define SIZE 5
#define EMPTY -1
#define DELETED 0
typedef int Set[SIZE];
typedef int Dictionary[SIZE];

/*  ======================================  */
void initDict(Dictionary D);
/*  ======================================  */
void populateDict(Set S, Dictionary D);
void insertEl(int el, Dictionary D);
/*  ======================================  */
bool isMember(int el, Dictionary D);
int hashKey(int el);
/*  ======================================  */
void deleteEl(int el, Dictionary D);
/*  ======================================  */
void displayDict(Dictionary D);
/*  ======================================  */

#endif