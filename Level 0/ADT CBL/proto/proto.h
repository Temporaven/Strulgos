#ifndef ADT_CBL_PROTO
#define ADT_CBL_PROTO

#include <stdbool.h>

#define CL_SIZE 10
#define WD_SIZE 20
#define EMPTY "EMP"
#define DELETED "DEL"
typedef struct {
    char words[WD_SIZE];
    int link;
} wordNodes;

typedef struct {
    wordNodes wNode[CL_SIZE];
    int avail;
} VirtHeap;

typedef struct {
    int startIdx;
    VirtHeap VH;
} cursorList;

/*  =============================================   */
void initializeCursorList(cursorList *CL);
/*cursorList createCursorList();      // another way of initializing*/
void displayCursorList(cursorList CL);
/*  =============================================   */
void insertFirst(char *word, cursorList *CL);
bool isEmpty(cursorList CL);
bool isFull(cursorList CL);
int allocSpace(VirtHeap *VH);
void insertSorted(char *word, cursorList *CL);
void insertLast(char *word, cursorList *CL);
/*  =============================================   */
void deleteFirst(cursorList *CL);
void deallocSpace(int pos, VirtHeap *VH);
void deleteWord(char *word, cursorList *CL);
void deleteLast(cursorList *CL);
/*  =============================================   */

#endif