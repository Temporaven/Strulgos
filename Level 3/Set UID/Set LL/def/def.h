#ifndef UID_LL_DEF
#define UID_LL_DEF

#include "../proto/proto.h"
#include <stdio.h>

/*  =============================== */
void init(Set *S) {
    (*S)=NULL;
}

void insertLast(int n, Set *S) {
    Set *trav;
    for(trav=S; (*trav)!=NULL; trav=&(*trav)->link){}
    Set temp=(Set)malloc(sizeof(struct node));
    if(temp!=NULL) {
        temp->num=n;
        temp->link=NULL;
        (*trav)=temp;
    }
}

void display(Set S) {
    Set trav;
    for(trav=S; trav!=NULL; trav=trav->link) {
        printf("%d ", trav->num);
    }
    puts("");
}
/*  =============================== */
Set uniSet(Set a, Set b) {
    Set newSet;
    init(&newSet);
    Set trav;
    for(trav=a; trav!=NULL; trav=trav->link) {
        insertLast(trav->num, &newSet);
    }
    for(trav=b; trav!=NULL; trav=trav->link) {
        if(!isMember(trav->num, newSet)) {
            insertLast(trav->num, &newSet);
        }
    }
    return newSet;
}

Set intSet(Set a, Set b) {
    Set newSet;
    init(&newSet);
    Set trav;
    for(trav=a; trav!=NULL; trav=trav->link) {
        if(isMember(trav->num, b)) {
            insertLast(trav->num, &newSet);
        }
    }
    return newSet;
}

Set difSet(Set a, Set b) {
    Set newSet;
    init(&newSet);
    Set trav;
    for(trav=a; trav!=NULL; trav=trav->link) {
        if(!isMember(trav->num, b)) {
            insertLast(trav->num, &newSet);
        }
    }
    for(trav=b; trav!=NULL; trav=trav->link) {
        if(!isMember(trav->num, a)) {
            insertLast(trav->num, &newSet);
        }
    }
    return newSet;
}
/*  =============================== */
bool isMember(int n, Set S) {
    Set trav;
    for(trav=S; trav!=NULL&&trav->num!=n; trav=trav->link){}
    return trav!=NULL;
}
/*  =============================== */

#endif