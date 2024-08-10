#ifndef ADT_CBL_DEF
#define ADT_CBL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  =============================================   */
void initializeCursorList(cursorList *CL) {
    CL->startIdx=-1;
    int x;
    for(x=0; x<CL_SIZE; ++x) {
        strcpy(CL->VH.wNode[x].words, EMPTY);
        CL->VH.wNode[x].link=(x<CL_SIZE-1)?x+1:-1;
    }
    CL->VH.avail=0;
}

/*
cursorList createCursorList() {
    cursorList curList;
    curList.startIdx = -1;
    int x;
    for(x = 0; x < CL_SIZE; x++) {
        strcpy(curList.VH.wNode[x].words, EMPTY);
        curList.VH.wNode[x].link = (x < CL_SIZE - 1) ? x + 1 : -1;
    }
    curList.VH.avail = 0;
    return curList;
}
*/

void displayCursorList(cursorList CL) {
    printf("\n\nContents of the List ::");
    printf("\n------------------------");
    printf("\n\n%-20s", "Word");
    printf("%-5s", "Index");
    printf("\n%-20s%-5s", "----", "-----");
    int trav;
    for(trav=CL.startIdx; trav!=-1; trav=CL.VH.wNode[trav].link) {
        printf("\n%-20s%3d", CL.VH.wNode[trav].words, CL.VH.wNode[trav].link);
    }
    puts("");
}
/*  =============================================   */
void insertFirst(char *word, cursorList *CL) {
    if(!isFull(*CL)) {
        int ndx=allocSpace(&CL->VH);
        if(ndx!=-1) {
            strcpy(CL->VH.wNode[ndx].words, word);
            CL->VH.wNode[ndx].link=CL->startIdx;
            CL->startIdx=ndx;
        }
    }
}

bool isEmpty(cursorList CL) {
    return CL.startIdx==-1;
}

bool isFull(cursorList CL) {
    return CL.VH.avail==-1;
}

int allocSpace(VirtHeap *VH) {
    int rdx=VH->avail;
    if(rdx!=-1) {
        VH->avail=VH->wNode[rdx].link;
    }
    return rdx;
}

void insertSorted(char *word, cursorList *CL) {
    if(!isFull(*CL)) {
        int *trav;
        for(trav=&CL->startIdx; *trav!=-1&&strcmp(word, CL->VH.wNode[*trav].words)>0; trav=&(CL->VH.wNode[*trav].link)){}
        int ndx=allocSpace(&CL->VH);
        if(ndx!=-1) {
            strcpy(CL->VH.wNode[ndx].words, word);
            CL->VH.wNode[ndx].link=*trav;
            *trav=ndx;
        }
    }
}

void insertLast(char *word, cursorList *CL) {
    if(!isFull(*CL)) {
        int *trav;
        for(trav=&CL->startIdx; *trav!=-1; trav=&(CL->VH.wNode[*trav].link)){}
        int ndx=allocSpace(&CL->VH);
        if(ndx!=-1) {
            strcpy(CL->VH.wNode[ndx].words, word);
            CL->VH.wNode[ndx].link=-1;
            *trav=ndx;
        }
    }
}
/*  =============================================   */
void deleteFirst(cursorList *CL) {
    if(!isEmpty(*CL)) {
        int temp=CL->startIdx;
        CL->startIdx=CL->VH.wNode[temp].link;
        deallocSpace(temp, &CL->VH);
    }
}

void deallocSpace(int pos, VirtHeap *VH) {
    if(pos>-1&&pos<CL_SIZE) {
        strcpy(VH->wNode[pos].words, DELETED);
        VH->wNode[pos].link=VH->avail;
        VH->avail=pos;
    }
}

void deleteWord(char *word, cursorList *CL) {
    if(!isEmpty(*CL)) {
        int *trav;
        for(trav=&CL->startIdx; *trav!=-1&&strcmp(word, CL->VH.wNode[*trav].words)!=0; trav=&(CL->VH.wNode[*trav].link)){}
        int temp=*trav;
        (*trav)=CL->VH.wNode[temp].link;
        deallocSpace(temp, &CL->VH);
    }
}

void deleteLast(cursorList *CL) {
    if(!isEmpty(*CL)) {
        int *trav;
        for(trav=&CL->startIdx; *trav!=-1&&CL->VH.wNode[*trav].link!=-1; trav=&(CL->VH.wNode[*trav].link)){}
        int temp=*trav;
        *trav=-1;
        deallocSpace(temp, &CL->VH);
    }
}
/*  =============================================   */

#endif