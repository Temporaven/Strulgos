#ifndef ADT_AL_PROTO
#define ADT_AL_PROTO

#include <stdbool.h>

#define COL_SIZE 10
#define ROW_SIZE 20
#define EMPTY "EMP"
#define DELETED "DEL"
typedef struct {
    char words[COL_SIZE][ROW_SIZE];
    int wordCount;
} arrayList;

/*  ============================================    */
void initializeArrList(arrayList *AL);
/*arrayList createArrList();         // another way of initializing*/
void displayArrList(arrayList AL);
/*  ============================================    */
void insertFirst(char *word, arrayList *AL);
bool isEmpty(arrayList AL);
bool isFull(arrayList AL);
void insertSorted(char *word, arrayList *AL);
void insertLast(char *word, arrayList *AL);
/*  ============================================    */
void deleteFirst(arrayList *AL);
void deleteWord(char *word, arrayList *AL);
void deleteLast(arrayList *AL);
/*  ============================================    */

#endif