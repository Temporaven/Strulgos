#ifndef QUEUE_DEF
#define QUEUE_DEF

#include <stdbool.h>

#define QUEUE_SIZE 10
typedef struct {
    int elem[QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void initialize(Queue *q) {
    q->front=0, q->rear=-1;
}

bool isFull(Queue q) {
    return q.front==(q.rear+2)%QUEUE_SIZE;
}

bool isEmpty(Queue q) {
    return q.front==(q.rear+1)%QUEUE_SIZE;
}

int front(Queue q) {
    int rf=0;
    if(!isEmpty(q)) {
        rf=q.elem[q.front];
    }
    return rf;
}

void enqueue(int el, Queue *q) {
    if(!isFull(*q)) {
        q->rear=(q->rear+1)%QUEUE_SIZE;
        q->elem[q->rear]=el;
    }
}

void dequeue(Queue *q) {
    if(!isEmpty(*q)) {
        q->front=(q->front+1)%QUEUE_SIZE;
    }
}

#endif