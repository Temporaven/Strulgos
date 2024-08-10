#ifndef QUEUE_A_DEF
#define QUEUE_A_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  ======================================  */
void init(queue *q) {
    q->front=0;
    q->rear=-1;
}
/*  ======================================  */
void populate(wordData data, queue *q) {
    int x;
    for(x=0; x<DATA_SET; ++x) {
        enqueue(data[x], q);
    }
}

void enqueue(char *wd, queue *q) {
    if(!isFull(*q)) {
        q->rear=(q->rear+1)%MAX_WORDS;
        strcpy(q->words[q->rear], wd);
    }
}

void insertSorted(char *wd, queue *q) {
    queue nq;
    init(&nq);
    int checker;
    for(checker=0; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)) {
        if(strcmp(wd, front(*q))<0&&checker==0) {
            enqueue(wd, &nq);
            checker=1;
        }
    }
    if(checker==0) {
        enqueue(wd, &nq);
    }
    *q=nq;
}

void insertFront(char *wd, queue *q) {
    queue nq;
    init(&nq);
    enqueue(wd, &nq);
    for(; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)){}
    *q=nq;
}
/*  ======================================  */
bool isEmpty(queue q) {
    return q.front==(q.rear+1)%MAX_WORDS;
}

bool isFull(queue q) {
    return q.front==(q.rear+2)%MAX_WORDS;
}

char *front(queue q) {
    char *rf=(char*)malloc(MAX_CHAR*sizeof(char));
    if(rf!=NULL) {
        if(!isEmpty(q)) {
            strcpy(rf, q.words[q.front]);
        }
    }
    return rf;
}
/*  ======================================  */
void dequeue(queue *q) {
    if(!isEmpty(*q)) {
        if(q->front!=q->rear) {
            q->front=(q->front+1)%MAX_WORDS;
        } else {
            init(q);
        }
    }
}

void deleteWord(char *wd, queue *q) {
    queue nq;
    init(&nq);
    for(; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)) {
        if(strcmp(wd, front(*q))==0) {
            dequeue(q);
        }
    }
    *q=nq;
}

void deleteRear(queue *q) {
    queue nq;
    init(&nq);
    for(; !isEmpty(*q)&&q->front!=q->rear; enqueue(front(*q), &nq), dequeue(q)){}
    dequeue(q);
    *q=nq;
}

/*  ======================================  */
void display(queue *q) {
    queue nq;
    init(&nq);
    for(; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)) {
        printf("%s ", front(*q));
    }
    *q=nq;
    printf("\n\n");
}
/*  ======================================  */

#endif