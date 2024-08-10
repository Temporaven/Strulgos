#ifndef STACK_CB_PROTO
#define STACK_CB_PROTO

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
    int top;
    vheap vhp;
}stack;

/*  =====================================   */
void init(stack *s);
/*  =====================================   */
void populate(Words data, stack *s);
void push(char *wd, stack *s);
void insertSorted(char *wd, stack *s);
void insertBott(char *wd, stack *s);
/*  =====================================   */
bool isEmpty(stack s);
bool isFull(stack s);
char *top(stack s);
/*  =====================================   */
void pop(stack *s);
void deleteWord(char *wd, stack *s);
void deleteBott(stack *s);
/*  =====================================   */
void display(stack *s);
/*  =====================================   */

#endif