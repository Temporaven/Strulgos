#ifndef ADT_LL_DEF
#define ADT_LL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  =============================================   */
void initializeLinkedList(linkedList *LL) {
    *LL=NULL;
}

/*
linkedList createLinkedList() {
    linkedList header;
    header = NULL;
    return header;
}
*/

void displayLinkedList(linkedList LL) {
    printf("\n\nContents of the List ::");
    printf("\n------------------------");
    printf("\n\n%-20s", "Word");
    printf("\n%-20s", "----");
    linkedList trav;
    for(trav=LL; trav!=NULL; trav=trav->link) {
        printf("\n%-20s", trav->words);
    }
    
    puts("");
}
/*  =============================================   */
void insertFirst(char *word, linkedList *LL) {
    linkedList temp=(linkedList)malloc(sizeof(struct lNode));
    if(temp!=NULL) {
        strcpy(temp->words, word);
        temp->link=*LL;
        *LL=temp;
    }
}

bool isEmpty(linkedList LL) {
    return LL==NULL;
}

void insertSorted(char *word, linkedList *LL) {
    linkedList *trav;
    for(trav=LL; *trav!=NULL&&strcmp(word, (*trav)->words)>0; trav=&(*trav)->link){}
    linkedList temp=(linkedList)malloc(sizeof(struct lNode));
    if(temp!=NULL) {
        strcpy(temp->words, word);
        temp->link=*trav;
        *trav=temp;
    }
}

void insertLast(char *word, linkedList *LL) {
    linkedList *trav;
    for(trav=LL; *trav!=NULL; trav=&(*trav)->link){}
    linkedList temp=(linkedList)malloc(sizeof(struct lNode));
    if(temp!=NULL) {
        strcpy(temp->words, word);
        temp->link=NULL;
        *trav=temp;
    }
}
/*  =============================================   */
void deleteFirst(linkedList *LL) {
    if(!isEmpty(*LL)) {
        linkedList temp=*LL;
        *LL=temp->link;
        free(temp);
    }
}

void deleteWord(char *word, linkedList *LL) {
    if(!isEmpty(*LL)) {
        linkedList *trav;
        for(trav=LL; *trav!=NULL&&strcmp(word, (*trav)->words)!=0; trav=&(*trav)->link){}
        linkedList temp=*trav;
        *trav=temp->link;
        free(temp);
    }
}

void deleteLast(linkedList *LL) {
    if(!isEmpty(*LL)) {
        linkedList *trav;
        for(trav=LL; *trav!=NULL&&(*trav)->link!=NULL; trav=&(*trav)->link){}
        linkedList temp=*trav;
        *trav=NULL;
        free(temp);
    }
}
/*  =============================================   */

#endif