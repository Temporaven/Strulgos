#include "dfs_def/dfscode.h"

int main(void) {
    Matrix matx={
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    displayMat(matx);
    
    int *resArr=DFS(1, matx);
    displayArr(resArr);

    return 0;
}