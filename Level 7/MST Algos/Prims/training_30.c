#include "def/def.h"

int main(void) {
    Matrix m={
        {INF, 2, 3, 3, INF, INF, INF},
        {2, INF, 4, INF, 3, INF, INF},
        {3, 4, INF, 5, 1, 6, INF},
        {3, INF, 5, INF, INF, 7, INF},
        {INF, 3, 1, INF, INF, 8, INF},
        {INF, INF, 6, 7, 8, INF, 9},
        {INF, INF, INF, INF, INF, INF, INF}
    };

    displayMat(m);

    path pst=prims(0, m);
    displayPath(pst);

    return 0;
}