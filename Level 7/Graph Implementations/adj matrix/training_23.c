#include "def/def.h"

int main(void) {
    labeledAdjMatrix adjMat=createLabeledAM();
    populateLabeledAM(&adjMat);
    displayLabeledAM(adjMat);

    return 0;
}