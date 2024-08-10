#ifndef ADT_AL_DEF
#define ADT_AL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  ============================================    */
void initializeArrList(arrayList *AL) {
    AL->wordCount=0;
    int x;
    for(x=0; x<COL_SIZE; ++x) {
        strcpy(AL->words[x], EMPTY);
    }
}

/*
arrayList createArrList() {
    arrayList arrList;
    arrList.wordCount = 0;
    int x;
    for(x = 0; x < COL_SIZE; x++) {
        strcpy(AL->words[x], EMPTY);
    }
    return arrList;
}
*/

void displayArrList(arrayList AL) {
    printf("\n\nContents of the List ::");
    printf("\n------------------------");
    printf("\nNo. of elements : %d", AL.wordCount);
    printf("\n\n%-20s", "Word");
    printf("%-5s", "Index");
    printf("\n%-20s%-5s", "----", "-----");
    int x;
    for(x=0; x<AL.wordCount; ++x) {
        printf("\n%-20s%3d", AL.words[x], x);
    }
    puts("");
}
/*  ============================================    */
void insertFirst(char *word, arrayList *AL) {
    if(!isFull(*AL)) {
        if(isEmpty(*AL)) {
            strcpy(AL->words[AL->wordCount], word);
            AL->wordCount++;
        }else {
            int x;
            for(x=AL->wordCount; x>0; --x) {
                strcpy(AL->words[x], AL->words[x-1]);
            }
            strcpy(AL->words[x], word);
            ++AL->wordCount;
        }
    }
}

bool isEmpty(arrayList AL) {
    return AL.wordCount==0;
}

bool isFull(arrayList AL) {
    return AL.wordCount==COL_SIZE;
}

void insertSorted(char *word, arrayList *AL) {
    int x;
    for(x=0; x<AL->wordCount && strcmp(word, AL->words[x])>0; ++x){}
    if(x<AL->wordCount) {
        int y;
        for(y=AL->wordCount; y>x; --y) {
            strcpy(AL->words[y], AL->words[y-1]);
        }
    }
    strcpy(AL->words[x], word);
    ++AL->wordCount;
}

void insertLast(char *word, arrayList *AL) {
    if(!isFull(*AL)) {
        strcpy(AL->words[AL->wordCount], word);
        ++AL->wordCount;
    }
}
/*  ============================================    */
void deleteFirst(arrayList *AL) {
    if(!isEmpty(*AL)) {
        int x;
        for(x=0; x<AL->wordCount-1; ++x) {
            strcpy(AL->words[x], AL->words[x+1]);
        }
        --AL->wordCount;
    }
}

void deleteWord(char *word, arrayList *AL) {
    if(!isEmpty(*AL)) {
        int x;
        for(x=0; x<AL->wordCount && strcmp(word, AL->words[x])!=0; ++x){}
        for(; x <AL->wordCount-1; x++) {
            strcpy(AL->words[x], AL->words[x+1]);
        }
        AL->wordCount--;
    }
}

void deleteLast(arrayList *AL) {
    if(!isEmpty(*AL)) {
        strcpy(AL->words[AL->wordCount-1], DELETED);
        --AL->wordCount;
    }
}
/*  ============================================    */

#endif