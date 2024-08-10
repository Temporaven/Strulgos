#ifndef OD_PROTO
#define OD_PROTO

#include <stdbool.h>

#define SIZE 10
typedef struct node {
    int num;
    struct node *link;
}*Node;
typedef int Set[SIZE];
typedef Node Dictionary[SIZE];

/*  ======================================  */
void init(Dictionary d);
/*  ======================================  */
void populateDict(Set s, Dictionary d);
void insertSorted(int n, Dictionary d);
/*  ======================================  */
int hash(int n);
bool isMember(int n, Dictionary d);
/*  ======================================  */
void deleteEl(int n, Dictionary d);
/*  ======================================  */
void display(Dictionary d);
/*  ======================================  */

#endif