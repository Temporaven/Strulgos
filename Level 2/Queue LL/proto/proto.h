#ifndef QUEUE_LL_PROTO
#define QUEUE_LL_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHAR 15
#define MAX_WORDS 3
typedef char Words[MAX_WORDS][MAX_CHAR];
typedef struct node {
    char word[MAX_CHAR];
    struct node *link;
}*wNode;
typedef struct {
    wNode front;
    wNode rear;
}queue;

/*  =====================================   */
void init(queue *q);
/*  =====================================   */
void populate(Words data, queue *q);
void enqueue(char *wd, queue *q);
void insertSorted(char *wd, queue *q);
void insertFront(char *wd, queue *q);
/*  =====================================   */
bool isEmpty(queue q);
char *front(queue q);
/*  =====================================   */
void dequeue(queue *q);
void deleteWord(char *wd, queue *q);
void deleteRear(queue *q);
/*  =====================================   */
void display(queue *q);
/*  =====================================   */

#endif