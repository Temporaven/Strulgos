#include "def/def.h"

int main(void) {
    labeledAdjMatrix am={
        {INF, INF, -2, INF},
        {4, INF, 3, INF},
        {INF, INF, INF, 2},
        {INF, -1, INF, INF}
    };
    displayMatrix(am);

    floydMatrix fm;
    floydsAlgo(am, fm);
    displayFMatrix(fm);

    return 0;
}