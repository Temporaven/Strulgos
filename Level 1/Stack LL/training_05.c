#include "def/def.h"

int main(void) {
    llStack lStack;
    initStack(&lStack);
    printf("{ Create }");
    displayStack(&lStack);

    insertBottom("adaption", &lStack);
    insertSorted("development", &lStack);
    insertSorted("game", &lStack);
    insertSorted("expectation", &lStack);
    push("question", &lStack);
    printf("\n\n{ Read & Update }");
    displayStack(&lStack);

    deleteBottom(&lStack);
    deleteWord("game", &lStack);
    pop(&lStack);
    printf("\n\n{ Delete }");
    displayStack(&lStack);

    return 0;
}