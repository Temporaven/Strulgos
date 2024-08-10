#ifndef QUEUE_CB_DEF
#define QUEUE_CB_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  =====================================   */
void init(queue *q) {
    q->front=q->rear=-1;
    int x;
    for(x=0; x<MAX_WORDS; ++x) {
        q->vhp.wnode[x].link=(x<MAX_WORDS-1)?x+1:-1;
    }
    q->vhp.avl=0;
}
/*  =====================================   */
void populate(Words data, queue *q) {
    int x;
    for(x=0; x<MAX_DATA; ++x) {
        enqueue(data[x], q);
    }
}

void enqueue(char *wd, queue *q) {
    if(!isFull(*q)) {
        int ndx=q->vhp.avl;
        if(ndx!=-1) {
            q->vhp.avl=q->vhp.wnode[ndx].link;
            strcpy(q->vhp.wnode[ndx].word, wd);
            q->vhp.wnode[ndx].link=-1;
            if(isEmpty(*q)) {
                q->front=ndx;
            } else {
                q->vhp.wnode[q->rear].link=ndx;
            }
            q->rear=ndx;
        }
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
    return q.front==-1;
}

bool isFull(queue q) {
    return q.vhp.avl==-1;
}

char *front(queue q) {
    char *rf=(char*)malloc(MAX_CHAR*sizeof(char));
    if(rf!=NULL) {
        strcpy(rf, q.vhp.wnode[q.front].word);
    }
    return rf;
}
/*  =====================================   */
void dequeue(queue *q) {
    if(!isEmpty(*q)) {
        int pos=q->front;
        if(q->front!=q->rear) {
            q->front=q->vhp.wnode[pos].link;
        } else {
            q->front=q->rear=-1;
        }
        if(pos>-1&&pos<MAX_WORDS) {
            q->vhp.wnode[pos].link=q->vhp.avl;
            q->vhp.avl=pos;
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
/*  =====================================   */
void display(queue *q) {
    queue nq;
    init(&nq);
    for(; !isEmpty(*q); enqueue(front(*q), &nq), dequeue(q)) {
        printf("%s ", front(*q));
    }
    printf("\n\n");
    *q=nq;
}

#endif