#ifndef BST_LL_PROTO
#define BST_LL_PROTO

#define SIZE 6
typedef int data[SIZE];
typedef struct node {
    int num;
    struct node *left;
    struct node *right;
}*bst;

/*  ==============================  */
void init(bst *t);
void populate(data d, bst *t);
void insert(int n, bst *t);
void deleteData(int n, bst *t);
/*  ==============================  */
void preOrder(bst t);
void inOrder(bst t);
void postOrder(bst t);
/*  ==============================  */

#endif