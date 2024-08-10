#include "def/def.h"

int main(void) {
    arrStack aStack;
    initStack(&aStack);
    printf("{ Create }");
    displayStack(&aStack);

    insertBottom("adaption", &aStack);
    insertSorted("development", &aStack);
    insertSorted("game", &aStack);
    insertSorted("expectation", &aStack);
    push("question", &aStack);
    printf("\n\n{ Read & Update }");
    displayStack(&aStack);

    deleteBottom(&aStack);
    deleteWord("game", &aStack);
    pop(&aStack);
    printf("\n\n{ Delete }");
    displayStack(&aStack);
    
    return 0;
}