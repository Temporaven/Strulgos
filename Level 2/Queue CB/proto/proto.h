#ifndef QUEUE_CB_PROTO
#define QUEUE_CB_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHAR 15
#define MAX_DATA 3
#define MAX_WORDS 6
typedef char Words[MAX_DATA][MAX_CHAR];
typedef struct {
    char word[MAX_CHAR];
    int link;
}node;
typedef struct {
    node wnode[MAX_WORDS];
    int avl;
}vheap;
typedef struct {
    vheap vhp;
    int front;
    int rear;
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
bool isFull(queue q);
char *front(queue q);
/*  =====================================   */
void dequeue(queue *q);
void deleteWord(char *wd, queue *q);
void deleteRear(queue *q);
/*  =====================================   */
void display(queue *q);
/*  =====================================   */

#endif