#ifndef STACK_LL_PROTO
#define STACK_LL_PROTO

#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
#define DELETED "DEL"
typedef struct wordNode {
    char words[MAX];
    struct wordNode *wLink;
} *wordStack;

typedef struct {
    wordStack top;
} llStack;

/*  ======================================= */
void initStack(llStack *LS);
void displayStack(llStack *LS);
/*  =========================================   */
void push(char *word, llStack *LS);
void insertSorted(char *word, llStack *LS);
void insertBottom(char *word, llStack *LS);
/*  =========================================   */
bool isEmpty(llStack LS);
char *top(llStack LS);
/*  =========================================   */
void pop(llStack *LS);
void deleteWord(char *word, llStack *LS);
void deleteBottom(llStack *LS);
/*  ======================================= */

#endif