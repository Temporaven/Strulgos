#ifndef STACK_A_DEF
#define STACK_A_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  =========================================   */
void initStack(arrStack *AS) {
    AS->top=-1;
}

void displayStack(arrStack *AS) {
    printf("\n\nContents of the Stack ::");
    printf("\n------------------------");
    printf("\n\n%-20s", "Word");
    printf("%-5s", "Index");
    printf("\n%-20s%-5s", "----", "-----");
    arrStack temp;
    initStack(&temp);
    char *topWord;

    for(topWord=top(*AS); !isEmpty(*AS); push(topWord, &temp), pop(AS), topWord=top(*AS)) {
        printf("\n%-20s%3d", topWord, AS->top);
    }
    for(topWord=top(temp); !isEmpty(temp); push(topWord, AS), pop(&temp), topWord=top(temp)){}
}
/*  =========================================   */
void push(char *word, arrStack *AS) {
    if(!isFull(*AS)) {
        AS->top++;
        strcpy(AS->words[AS->top], word);
    }
}

void insertSorted(char *word, arrStack *AS) {
    if(!isFull(*AS)) {
        arrStack temp;
        initStack(&temp);

        for(; !isEmpty(*AS)&&strcmp(word, AS->words[AS->top])<0; push(top(*AS), &temp), pop(AS)){}
        push(word, AS);
        for(; !isEmpty(temp); push(top(temp), AS), pop(&temp)){}
    }
}

void insertBottom(char *word, arrStack *AS) {
    if(!isFull(*AS)) {
        arrStack temp;
        initStack(&temp);

        for(; !isEmpty(*AS); push(top(*AS), &temp), pop(AS)){}
        push(word, AS);
        for(; !isEmpty(temp); push(top(temp), AS), pop(&temp)){}
    }
}
/*  =========================================   */
bool isEmpty(arrStack AS) {
    return AS.top==-1;
}

bool isFull(arrStack AS) {
    return AS.top==COL_SIZE-1;
}

char *top(arrStack AS) {
    char *rtop=(char *)malloc(ROW_SIZE*sizeof(char));
    if(rtop!=NULL) {
        if(!isEmpty(AS)) {
            strcpy(rtop, AS.words[AS.top]);
        }
    }
    return rtop;
}
/*  =========================================   */
void pop(arrStack *AS) {
    if(!isEmpty(*AS)) {
        strcpy(AS->words[AS->top], DELETED);
        AS->top--;
    }
}

void deleteWord(char *word, arrStack *AS) {
    if(!isEmpty(*AS)) {
        arrStack temp;
        initStack(&temp);

        for(; !isEmpty(*AS)&&strcmp(word, AS->words[AS->top])!=0; push(top(*AS), &temp), pop(AS)){}
        pop(AS);
        for(; !isEmpty(temp); push(top(temp), AS), pop(&temp)){}
    }
}

void deleteBottom(arrStack *AS) {
    if(!isEmpty(*AS)) {
        arrStack temp;
        initStack(&temp);

        for(; !isEmpty(*AS)&&AS->top!=0; push(top(*AS), &temp), pop(AS)){}
        pop(AS);
        for(; !isEmpty(temp); push(top(temp), AS), pop(&temp)){}
    }
}
/*  ======================================= */

#endif