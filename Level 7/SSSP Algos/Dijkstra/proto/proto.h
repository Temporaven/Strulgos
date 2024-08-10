#ifndef DIJKSTRA_PROTO
#define DIJKSTRA_PROTO

#include <limits.h>
#define INF INT_MAX
#define MAT_MAX 5
#define ARR_MAX 5

typedef int Matrix[MAT_MAX][MAT_MAX];

typedef char vertexType;
typedef struct {
    vertexType tail;
    vertexType head;
    int weight;
}edgeType;
typedef struct {
    // if n vertices, then there must be n-1 edges in the sssp
    edgeType EI[ARR_MAX-1];
    int edgeCount;
    int totalWeight;
}path;

path dijkstra(int src, Matrix m);
void initPath(path *sp);
void insertToPath(int tl, int hd, int wt, path *sp);
void displayMat(Matrix m);
void displayPath(path sp);

#endif