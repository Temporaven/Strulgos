#include "def/def.h"

int main(void) {
    Matrix m={
        {INF, 4, 2, INF, INF},
        {INF, INF, 3, 2, 3},
        {INF, 1, INF, 4, 5},
        {INF, INF, INF, INF, INF},
        {INF, INF, INF, 1, INF}
    };
    displayMat(m);

    path dsp=dijkstra(0, m);
    displayPath(dsp);

    return 0;
}