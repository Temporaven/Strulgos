#ifndef STACK_LL_DEF
#define STACK_LL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  ======================================= */
void initStack(llStack *LS) {
    LS->top=NULL;
}

void displayStack(llStack *LS) {
    printf("\n\nContents of the Stack ::");
    printf("\n------------------------");
    printf("\n\n%-20s", "Word");
    printf("%-5s", "Address");
    printf("\n%-20s%-5s", "----", "-------");
    llStack temp;
    initStack(&temp);
    char *topWord;

    for(topWord=top(*LS); !isEmpty(*LS); push(topWord, &temp), pop(LS), topWord=top(*LS)) {
        printf("\n%-20s%3x", topWord, LS->top);
    }
    for(topWord=top(temp); !isEmpty(temp); push(topWord, LS), pop(&temp), topWord=top(temp)){}
}
/*  =========================================   */
void push(char *word, llStack *LS) {
    wordStack temp=(wordStack)malloc(sizeof(struct wordNode));
    if(temp!=NULL) {
        strcpy(temp->words, word);
        temp->wLink=LS->top;
        LS->top=temp;
    }
}

void insertSorted(char *word, llStack *LS) {
    llStack temp;
    initStack(&temp);

    for(; !isEmpty(*LS)&&strcmp(word, LS->top->words)<0; push(top(*LS), &temp), pop(LS)){}
    push(word, LS);
    for(; !isEmpty(temp); push(top(temp), LS), pop(&temp)){}
}

void insertBottom(char *word, llStack *LS) {
    llStack temp;
    initStack(&temp);

    for(; !isEmpty(*LS); push(top(*LS), &temp), pop(LS)){}
    push(word, LS);
    for(; !isEmpty(temp); push(top(temp), LS), pop(&temp)){}
}
/*  =========================================   */
bool isEmpty(llStack LS) {
    return LS.top == NULL;
}

char *top(llStack LS) {
    char *rtop=(char*)malloc(MAX*sizeof(char));
    if(rtop != NULL) {
        if(!isEmpty(LS)) {
            strcpy(rtop, LS.top->words);
        }
    }
    return rtop;
}
/*  =========================================   */
void pop(llStack *LS) {
    if(!isEmpty(*LS)) {
        wordStack temp=LS->top;
        LS->top=temp->wLink;
        free(temp);
    }
}

void deleteWord(char *word, llStack *LS) {
    if(!isEmpty(*LS)) {
        llStack temp;
        initStack(&temp);

        for(; !isEmpty(*LS)&&strcmp(word, LS->top->words)!=0; push(top(*LS), &temp), pop(LS)){}
        pop(LS);
        for(; !isEmpty(temp); push(top(temp), LS), pop(&temp)){}
    }
}

void deleteBottom(llStack *LS) {
    if(!isEmpty(*LS)) {
        llStack temp;
        initStack(&temp);

        for(; !isEmpty(*LS)&&LS->top->wLink!=NULL; push(top(*LS), &temp), pop(LS)){}
        pop(LS);
        for(; !isEmpty(temp); push(top(temp), LS), pop(&temp)){}
    }
}
/*  ======================================= */

#endif