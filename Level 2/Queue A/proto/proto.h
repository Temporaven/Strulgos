#ifndef QUEUE_A_PROTO
#define QUEUE_A_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHAR 15
#define DATA_SET 3
#define MAX_WORDS 8
typedef char wordData[DATA_SET][MAX_CHAR];
typedef struct {
    char words[MAX_WORDS][MAX_CHAR];
    int front;
    int rear;
}queue;

/*  ======================================  */
void init(queue *q);
/*  ======================================  */
void populate(wordData data, queue *q);
void enqueue(char *wd, queue *q);
void insertSorted(char *wd, queue *q);
void insertFront(char *wd, queue *q);
/*  ======================================  */
bool isEmpty(queue q);
bool isFull(queue q);
char *front(queue q);
/*  ======================================  */
void dequeue(queue *q);
void deleteWord(char *wd, queue *q);
void deleteRear(queue *q);
/*  ======================================  */
void display(queue *q);
/*  ======================================  */

#endif