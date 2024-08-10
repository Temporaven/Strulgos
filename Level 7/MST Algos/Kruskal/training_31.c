#include "kruskal_def/kruskalcode.h"

int main(void) {
    Matrix matx={
        {INF, 2, 3, 3, INF, INF, INF},
        {2, INF, 4, INF, 3, INF, INF},
        {3, 4, INF, 5, 1, INF, INF},
        {3, INF, 5, INF, INF, 7, INF},
        {INF, 3, 1, INF, INF, 8, INF},
        {INF, INF, INF, 7, 8, INF, 9},
        {INF, INF, INF, INF, INF, 9, INF},
    };
    displayMatrix(matx);

    path mstk=kruskall(matx);
    displayPath(mstk);

    return 0;
}