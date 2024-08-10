#ifndef WARSHALL_PROTO
#define WARSHALL_PROTO

#define INF 0xFFFFFFF
#define MAT_MAX 4

typedef int labeledAdjMatrix[MAT_MAX][MAT_MAX];
typedef int warshallMatrix[MAT_MAX][MAT_MAX];

void warshallsAlgo(labeledAdjMatrix AM, warshallMatrix WM);
void displayMatrix(labeledAdjMatrix AM);
void displayWMatrix(warshallMatrix WM);

#endif