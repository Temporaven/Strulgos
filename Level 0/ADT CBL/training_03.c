#include "def/def.h"

int main(void) {
    cursorList cList;
    initializeCursorList(&cList);

    /*
    cursorList cursoList = createCursorList();
    */
   
    printf("{ Create }");
    displayCursorList(cList);

    insertLast("question", &cList);
    insertSorted("development", &cList);
    insertSorted("game", &cList);
    insertSorted("expectation", &cList);
    insertFirst("adaption", &cList);
    printf("{ Read & Update }");
    displayCursorList(cList);

    deleteLast(&cList);
    deleteWord("game", &cList);
    deleteFirst(&cList);
    printf("\n{ Delete }");
    displayCursorList(cList);

    return 0;
}