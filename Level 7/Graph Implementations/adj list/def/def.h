#ifndef ADJ_LIST_DEF
#define ADJ_LIST_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  ==================================================  */
labeledAdjList createLabeledAL() {
    labeledAdjList AL;
    int x;
    for(x=0; x<MAX_VERTEX; ++x) {
        AL.tail[x]=NULL;
    }
    AL.edgeCount=0;
    return AL;
}
/*  ==================================================  */
void populateLabeledAL(labeledAdjList *AL) {
    const int countryCount=8;
    edgeType countryData[]={
                            {"Singapore", "Philippines", 2355}, {"Canada", "Philippines", 11138}, 
                            {"Philippines", "USA", 13215}, {"USA", "Canada", 2261},
                            {"Philippines", "Canada", 11138}, {"USA", "Philippines", 13215}, 
                            {"Philippines", "Singapore", 2355}, {"Canada", "USA", 2261}
                           };
    int x;
    for(x=0; x<countryCount; ++x) {
        insertToAL(countryData[x], AL);
    }
}

void insertToAL(edgeType data, labeledAdjList *AL) {
    adjList *trav;
    for(trav=&AL->tail[getNdx(data.countryTail)]; *trav!=NULL&&strcmp(data.countryHead, (*trav)->cInfo.adjCountry)>0; trav=&(*trav)->cLink){}
    if(*trav!=NULL&&strcmp((*trav)->cInfo.adjCountry, data.countryHead)==0) {
        (*trav)->cInfo.weight=(data.kmDistance<(*trav)->cInfo.weight)?data.kmDistance:(*trav)->cInfo.weight;
    } else {
        adjList temp=(adjList)malloc(sizeof(struct adjNode));
        if(temp!=NULL) {
            strcpy(temp->cInfo.adjCountry, data.countryHead);
            temp->cInfo.weight=data.kmDistance;
            temp->cLink=*trav;
            *trav=temp;
        }
        AL->edgeCount++;
    }
}

int getNdx(char *countryName) {
    int x, sum;
    for(x=0, sum=0; countryName[x]!='\0'; ++x) {
        if(countryName[x]>='A'&&countryName[x]<='Z') {
            sum+=countryName[x]-'A';
        } else if(countryName[x]>='a'&&countryName[x]<='z') {
            sum+=countryName[x]-'a';
        }
    }
    sum/=strlen(countryName);
    return sum%=10;
}
/*  ==================================================  */
void displayLabeledAL(labeledAdjList AL) {
    printf("\n%s", "The Adjacency List:");
    printf("\n%s", "-------------------");
    printf("\n(%d) - %s\t\t", 0, "Singapore");
    printf("(%d) - %s", 1, "Philippines");
    printf("\n(%d) - %s\t\t", 2, "USA");
    printf("(%d) - %s", 3, "Canada");
    printf("\n-----------------------------------------");
    int x;
    adjList trav;
    for(x=0; x<MAX_VERTEX; ++x) {
        printf("\n[%d]: ", x);
        for(trav=AL.tail[x]; trav!=NULL; trav=trav->cLink) {
            printf("%s (%d)\t", trav->cInfo.adjCountry, trav->cInfo.weight);
        }
    }
    printf("\n\nNumber of arcs: %d\n\n", AL.edgeCount);
}
/*  ==================================================  */

#endif