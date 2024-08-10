#ifndef FLOYD_PROTO
#define FLOYD_PROTO

#define INF 0xFFFFFFF
#define MAT_MAX 4

typedef int labeledAdjMatrix[MAT_MAX][MAT_MAX];
typedef int floydMatrix[MAT_MAX][MAT_MAX];

void floydsAlgo(labeledAdjMatrix AM, floydMatrix FM);
void displayMatrix(labeledAdjMatrix AM);
void displayFMatrix(floydMatrix FM);

#endif