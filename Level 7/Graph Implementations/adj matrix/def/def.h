#ifndef ADJ_MATRIX_DEF
#define ADJ_MATRIX_DEF

#include "../proto/proto.h"
#include <stdio.h>
#include <string.h>

/*  ======================================================  */
labeledAdjMatrix createLabeledAM() {
    labeledAdjMatrix AM;
    int x, y;
    for(x=0; x<MAX_VERTEX; ++x) {
        for(y=0; y<MAX_VERTEX; ++y) {
            AM.matrix[x][y]=SENTINEL;
        }
    }
    AM.edgeCount=0;
    return AM;
}
/*  ======================================================  */
void populateLabeledAM(labeledAdjMatrix *AM) {
    const int countryCount=8;
    edgeType countryData[]={
                            {"Singapore", "Philippines", 2355}, {"Canada", "Philippines", 11138}, 
                            {"Philippines", "USA", 13215}, {"USA", "Canada", 2261},
                            {"Philippines", "Canada", 11138}, {"USA", "Philippines", 13215}, 
                            {"Philippines", "Singapore", 2355}, {"Canada", "USA", 2261}
                           };
    int x;
    for(x=0; x<countryCount; ++x) {
        insertWeight(countryData[x], AM);
    }
}

void insertWeight(edgeType data, labeledAdjMatrix *AM) {
    int tailNdx=getNdx(data.countryTail), headNdx=getNdx(data.countryHead);
    AM->matrix[tailNdx][headNdx]=data.kmDistance;
    AM->edgeCount++;
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
/*  ======================================================  */
void displayLabeledAM(labeledAdjMatrix AM) {
    int x, y;
    printf("\n%s", "The Adjacency Matrix:");
    printf("\n%s", "---------------------");
    printf("\n(%d) - %s\t\t", 0, "Singapore");
    printf("(%d) - %s", 1, "Philippines");
    printf("\n(%d) - %s\t\t", 2, "USA");
    printf("(%d) - %s", 3, "Canada");
    printf("\n-----------------------------------------");
    for(x=0; x<MAX_VERTEX; ++x) {
        printf("\n[%d]: ", x);
        for(y=0; y<MAX_VERTEX; ++y) {
            (AM.matrix[x][y]==SENTINEL)?printf("%c\t", 236):printf("%d\t", AM.matrix[x][y]);
        }
    }
    printf("\n\nNumber of arcs: %d\n\n", AM.edgeCount);
}
/*  ======================================================  */

#endif