#ifndef OD_DEF
#define OD_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdlib.h>

/*  ======================================= */
void init(Dictionary d) {
    int x;
    for(x=0; x<SIZE; x++) {
        d[x]=NULL;
    }
}
/*  ======================================= */
void populateDict(Set s, Dictionary d) {
    int x;
    for(x=0; x<SIZE; x++) {
        insertSorted(s[x], d);
    }
}

void insertSorted(int n, Dictionary d) {
    int ndx=hash(n);
    if(!isMember(n, d)) {
        Node *trav;
        for(trav=&d[ndx]; *trav!=NULL&&n>(*trav)->num; trav=&(*trav)->link){}
        Node temp=(Node)malloc(sizeof(struct node));
        if(temp!=NULL) {
            temp->num=n;
            temp->link=*trav;
            *trav=temp;
        }
    }
}
/*  ======================================= */
int hash(int n) {
    return n%SIZE;
}

bool isMember(int n, Dictionary d) {
    int ndx=hash(n);
    Node trav;
    for(trav=d[ndx]; trav!=NULL&&trav->num!=n; trav=trav->link){}
    return trav!=NULL;
}
/*  ======================================= */
void deleteEl(int n, Dictionary d) {
    int ndx=hash(n);
    Node *trav;
    for(trav=&d[ndx]; *trav!=NULL&&(*trav)->num!=n; trav=&(*trav)->link){}
    Node temp=*trav;
    *trav=temp->link;
    free(temp);
}
/*  ======================================= */
void display(Dictionary d) {
    int x;
    for(x=0; x<SIZE; x++) {
        printf("[%d]: ", x);
        Node trav;
        for(trav=d[x]; trav!=NULL; trav=trav->link) {
            printf("%d->", trav->num);
        }
        puts("");
    }
    puts("");
}
/*  ======================================= */

#endif