#ifndef STACK_DEF
#define STACK_DEF

#include <stdbool.h>

#define STACK_MAX 10
typedef struct {
    int elem[STACK_MAX];
    int top;
}Stack;

void initialize(Stack *s) {
    s->top=-1;
}

bool isFull(Stack s) {
    return s.top==STACK_MAX-1;
}

bool isEmpty(Stack s) {
    return s.top==-1;
}

int top(Stack s) {
    int rt=0;
    if(!isEmpty(s)) {
        rt=s.elem[s.top];
    }
    return rt;
}

void push(int el, Stack *s) {
    if(!isFull(*s)) {
        s->top++;
        s->elem[s->top]=el;
    }
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

#endif