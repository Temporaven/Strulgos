#include "def/def.h"

int main(void) {
    linkedList hd;
    initializeLinkedList(&hd);

    /*
    linkedList hed = createLinkedList()
    */
   
    printf("{ Create }");
    displayLinkedList(hd);

    insertLast("question", &hd);
    insertSorted("development", &hd);
    insertSorted("game", &hd);
    insertSorted("expectation", &hd);
    insertFirst("adaption", &hd);
    printf("{ Read & Update }");
    displayLinkedList(hd);

    deleteLast(&hd);
    deleteWord("game", &hd);
    deleteFirst(&hd);
    printf("\n{ Delete }");
    displayLinkedList(hd);

    return 0;
}