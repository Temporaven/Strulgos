#ifndef PRIM_PROTO
#define PRIM_PROTO

#include <limits.h>

#define INF INT_MAX
#define MAT_MAX 7
#define ARR_MAX 7

typedef int Matrix[MAT_MAX][MAT_MAX];

typedef char vertexType;
typedef struct {
    vertexType tail;
    vertexType head;
    int weight;
}edgeType;
typedef struct {
    edgeType edgeInfo[ARR_MAX-1];
    int edgeCount;
    int totalWeight;
}path;

path prims(int src, Matrix m);
void initPath(path *pt);
void insertToPath(int tl, int hd, int wt, path *sp);
void displayMat(Matrix m);
void displayPath(path pt);

#endif