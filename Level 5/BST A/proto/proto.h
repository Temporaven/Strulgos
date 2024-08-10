#ifndef BST_A_PROTO
#define BST_A_PROTO

#define RSIZE 3
#define CSIZE 6
#define EMPTY -1

typedef int Data[CSIZE];
typedef int Tree[RSIZE][CSIZE];

/*  ============================    */
void init(Tree T);
void populate(Data D, Tree T);
void displayData(Tree T);
/*  ============================    */
void preOrder(Tree T, int node);
void inOrder(Tree T, int node);
void postOrder(Tree T, int node);
/*  ============================    */

#endif