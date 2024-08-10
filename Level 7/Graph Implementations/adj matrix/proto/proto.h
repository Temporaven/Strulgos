#ifndef ADJ_MATRIX_PROTO
#define ADJ_MATRIX_PROTO

#define MAX_VERTEX 4
#define SENTINEL 0xFFFF
typedef char countryVertex;
typedef int labeledGraph;

typedef struct {
    countryVertex countryTail[12];
    countryVertex countryHead[12];
    int kmDistance;
}edgeType;

typedef struct {
    labeledGraph matrix[MAX_VERTEX][MAX_VERTEX];
    int edgeCount;
}labeledAdjMatrix;

/*  ======================================================  */
labeledAdjMatrix createLabeledAM();
/*  ======================================================  */
void populateLabeledAM(labeledAdjMatrix *AM);
void insertWeight(edgeType data, labeledAdjMatrix *AM);
int getNdx(char *countryName);
/*  ======================================================  */
void displayLabeledAM(labeledAdjMatrix AM);
/*  ======================================================  */

#endif