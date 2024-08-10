#ifndef ADJ_LIST_PROTO
#define ADJ_LIST_PROTO

#define MAX_VERTEX 4

typedef char countryVertex;
typedef int labeledGraph;

typedef struct {
    countryVertex countryTail[12];
    countryVertex countryHead[12];
    int kmDistance;
}edgeType;

typedef struct {
    countryVertex adjCountry[12];
    int weight;
}adjType;

typedef struct adjNode {
    adjType cInfo;
    struct adjNode *cLink;
}*adjList;

typedef struct {
    adjList tail[MAX_VERTEX];
    int edgeCount;
}labeledAdjList;

/*  ==================================================  */
labeledAdjList createLabeledAL();
/*  ==================================================  */
void populateLabeledAL(labeledAdjList *AL);
void insertToAL(edgeType data, labeledAdjList *AL);
int getNdx(char *countryName);
/*  ==================================================  */
void displayLabeledAL(labeledAdjList AL);
/*  ==================================================  */

#endif