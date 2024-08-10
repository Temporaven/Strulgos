#include "def/def.h"

int main(void) {
    labeledAdjList adjLt=createLabeledAL();
    populateLabeledAL(&adjLt);
    displayLabeledAL(adjLt);

    return 0;
}