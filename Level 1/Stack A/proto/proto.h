#ifndef STACK_A_PROTO
#define STACK_A_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define COL_SIZE 8
#define ROW_SIZE 20
#define DELETED "DEL"
typedef struct {
    char words[COL_SIZE][ROW_SIZE];
    int top;
} arrStack;

/*  ======================================= */
void initStack(arrStack *AS);
void displayStack(arrStack *AS);
/*  =========================================   */
void push(char *word, arrStack *AS);
void insertSorted(char *word, arrStack *AS);
void insertBottom(char *word, arrStack *AS);
/*  =========================================   */
bool isEmpty(arrStack AS);
bool isFull(arrStack AS);
char *top(arrStack AS);
/*  =========================================   */
void pop(arrStack *AS);
void deleteWord(char *word, arrStack *AS);
void deleteBottom(arrStack *AS);
/*  ======================================= */

#endif