#include "bfs_def/bfscode.h"

int main(void) {
    Matrix matx={
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };
    displayMat(matx);

    int *resArr=BFS(4, matx);
    displayArr(resArr);
    
    return 0;
}