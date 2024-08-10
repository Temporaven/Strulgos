#ifndef ADT_LL_PROTO
#define ADT_LL_PROTO

#include <stdbool.h>
#define SIZE 20
typedef struct lNode {
    char words[SIZE];
    struct lNode *link;
} *linkedList;

/*  =============================================   */
void initializeLinkedList(linkedList *LL);
/*linkedList createLinkedList();    // another way to initialize*/
void displayLinkedList(linkedList LL);
/*  =============================================   */
void insertFirst(char *word, linkedList *LL);
bool isEmpty(linkedList LL);
void insertSorted(char *word, linkedList *LL);
void insertLast(char *word, linkedList *LL);
/*  =============================================   */
void deleteFirst(linkedList *LL);
void deleteWord(char *word, linkedList *LL);
void deleteLast(linkedList *LL);
/*  =============================================   */

#endif