#include "def/def.h"

int main(void) {
    arrayList aList;
    initializeArrList(&aList);

    /*
    arrayList aLt = createArrList();
    */
   
    printf("{ Create }");
    displayArrList(aList);

    insertLast("question", &aList);
    insertSorted("development", &aList);
    insertSorted("game", &aList);
    insertSorted("expectation", &aList);
    insertFirst("adaption", &aList);
    printf("\n{ Read & Update }");
    displayArrList(aList);

    deleteLast(&aList);
    deleteWord("game", &aList);
    deleteFirst(&aList);
    printf("\n{ Delete }");
    displayArrList(aList);
    
    return 0;
}
