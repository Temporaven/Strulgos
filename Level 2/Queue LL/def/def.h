#ifndef QUEUE_LL_DEF
#define QUEUE_LL_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  =====================================   */
void init(queue *q) {
    q->front=q->rear=NULL;
}
/*  =====================================   */
void populate(Words data, queue *q) {
    int x;
    for(x=0; x<MAX_WORDS; ++x) {
        enqueue(data[x], q);
    }
}

void enqueue(char *wd, queue *q) {
    wNode temp=(wNode)malloc(sizeof(struct node));
    if(temp!=NULL) {
        strcpy(temp->word, wd);
        temp->link=NULL;
        if(isEmpty(*q)) {
            q->front=temp;
        } else {
            q->rear->link=temp;
        }
        q->rear=temp;
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
/*  =====================================   */
bool isEmpty(queue q) {
    return q.front==NULL;
}

char *front(queue q) {
    char *rf=(char*)malloc(MAX_CHAR*sizeof(char));
    if(rf!=NULL) {
        if(!isEmpty(q)) {
            strcpy(rf, q.front->word);
        }
    }
    return rf;
}
/*  =====================================   */
void dequeue(queue *q) {
    if(!isEmpty(*q)) {
        wNode temp=q->front;
        if(q->front!=q->rear) {
            q->front=temp->link;
        } else {
            q->front=q->rear=NULL;
        }
        free(temp);
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
/*  =====================================   */
void display(queue *q) {
    queue nq;
    init(&nq);
    for(; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)) {
        printf("%s ", front(*q));
    }
    *q=nq;
    printf("\n\n");
}
/*  =====================================   */

#endif