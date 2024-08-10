#include "def/def.h"

int main(void) {
    Dictionary d;
    initDict(d);
    Set s={50, 70, 76, 85, 93};
    populateDict(s, d);
    displayDict(d);

    deleteEl(85, d);
    displayDict(d);
    
    return 0;
}