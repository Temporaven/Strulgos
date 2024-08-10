#ifndef BST_LL_DEF
#define BST_LL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdlib.h>

/*  ==============================  */
void init(bst *t) {
    *t=NULL;
}

void populate(data d, bst *t) {
    int x;
    for(x=0; x<SIZE; ++x) {
        insert(d[x], t);
    }
}
/*  ==============================  */
void insert(int n, bst *t) {
    bst temp=(bst)malloc(sizeof(struct node));
    if(temp!=NULL) {
        temp->num=n;
        temp->left=temp->right=NULL;
        if(*t==NULL) {
            *t=temp;
        } else {
            bst *trav;
            for(trav=t; *trav!=NULL; ) {
                trav=(n<(*trav)->num)?&(*trav)->left:&(*trav)->right;
            }
            *trav=temp;
        }
    }
}

void deleteData(int n, bst *t) {
    bst *trav;
    for(trav=t; *trav!=NULL&&n!=(*trav)->num; ) {
        trav=(n<(*trav)->num)?&(*trav)->left:&(*trav)->right;
    }
    // If node has 2 children, replace the node w/ its successor
    if((*trav)->left!=NULL&&(*trav)->right!=NULL) {
        bst *succ;
        for(succ=&(*trav)->right; (*succ)->left!=NULL; succ=&(*succ)->left){}
        bst temp=*succ;
        (*trav)->num=temp->num;
        // Checks if the node that temp is pointing to to be deleted has 2 children or only 1
        if(temp->right!=NULL) {
            *succ=temp->right;
        } else {
            *succ=NULL;
        }
        free(temp);
    } else if((*trav)->left==NULL&&(*trav)->right==NULL) {  // Checks if the node to be deleted is a leaf node
        bst temp=*trav;
        *trav=NULL;
        free(temp);
    } else {    // The node to be deleted has 1 child
        bst temp=*trav;
        *trav=(temp->left!=NULL)?temp->left:temp->right;
        free(temp);
    }
}
/*  ==============================  */
void preOrder(bst t) {
    if(t!=NULL) {
        printf("%d ", t->num);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(bst t) {
    if(t!=NULL) {
        inOrder(t->left);
        printf("%d ", t->num);
        inOrder(t->right);
    }
}

void postOrder(bst t) {
    if(t!=NULL) {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->num);
    }
}
/*  ==============================  */

#endif