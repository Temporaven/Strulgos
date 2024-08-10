#ifndef STACK_CB_DEF
#define STACK_CB_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  =====================================   */
void init(stack *s) {
    s->top=-1;
    int x;
    for(x=0; x<MAX_WORDS; ++x) {
        s->vhp.wnode[x].link=(x<MAX_WORDS-1)?x+1:-1;
    }
    s->vhp.avl=0;
}
/*  =====================================   */
void populate(Words data, stack *s) {
    int x;
    for(x=0; x<MAX_DATA; ++x) {
        push(data[x], s);
    }
}

void push(char *wd, stack *s) {
    if(!isFull(*s)) {
        int ndx=s->vhp.avl;
        if(ndx!=-1) {
            s->vhp.avl=s->vhp.wnode[ndx].link;
            strcpy(s->vhp.wnode[ndx].word, wd);
            s->vhp.wnode[ndx].link=s->top;
            s->top=ndx;
        }
    }
}

void insertSorted(char *wd, stack *s) {
    stack tmp;
    init(&tmp);
    for(; !isEmpty(*s)&&strcmp(wd, top(*s))<0; push(top(*s), &tmp), pop(s)){}
    push(wd, s);
    for(; !isEmpty(tmp); push(top(tmp), s), pop(&tmp)){}
}

void insertBott(char *wd, stack *s) {
    stack tmp;
    init(&tmp);
    for(; !isEmpty(*s); push(top(*s), &tmp), pop(s)){}
    push(wd, s);
    for(; !isEmpty(tmp); push(top(tmp), s), pop(&tmp)){}
}
/*  =====================================   */
bool isEmpty(stack s) {
    return s.top==-1;
}

bool isFull(stack s) {
    return s.vhp.avl==-1;
}

char *top(stack s) {
    char *rt=(char*)malloc(MAX_CHAR*sizeof(char));
    if(rt!=NULL) {
        strcpy(rt, s.vhp.wnode[s.top].word);
    }
    return rt;
}
/*  =====================================   */
void pop(stack *s) {
    if(!isEmpty(*s)) {
        int temp=s->top;
        s->top=(s->vhp.wnode[temp].link!=-1)?s->vhp.wnode[temp].link:-1;
        if(temp>-1&&temp<MAX_WORDS) {
            s->vhp.wnode[temp].link=s->vhp.avl;
            s->vhp.avl=temp;
        }
    }
}

void deleteWord(char *wd, stack *s) {
    stack tmp;
    init(&tmp);
    for(; !isEmpty(*s)&&strcmp(wd, top(*s))!=0; push(top(*s), &tmp), pop(s)){}
    pop(s);
    for(; !isEmpty(tmp); push(top(tmp), s), pop(&tmp)){}
}

void deleteBott(stack *s) {
    stack tmp;
    init(&tmp);
    for(; !isEmpty(*s)&&s->top!=0; push(top(*s), &tmp), pop(s)){}
    pop(s);
    for(; !isEmpty(tmp); push(top(tmp), s), pop(&tmp)){}
}
/*  =====================================   */
void display(stack *s) {
    stack tmp;
    init(&tmp);
    for(; !isEmpty(*s); push(top(*s), &tmp), pop(s)) {
        printf("%s ", top(*s));
    }
    for(; !isEmpty(tmp); push(top(tmp), s), pop(&tmp)){}
    printf("\n\n");
}
/*  =====================================   */

#endif