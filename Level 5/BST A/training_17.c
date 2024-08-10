#include "def/def.h"

int main(void) {
    Tree t;
    Data d={10, 20, 8, 7, 6, 31};
    init(t);
    populate(d, t);
    puts("Tree Data:");
    displayData(t);   // Just to show if the 2d arr was populated properly

    puts("Preorder Traversal:");
    preOrder(t, 0);
    puts("");

    puts("Inorder Traversal:");
    inOrder(t, 0);
    puts("");

    puts("Postorder Traversal:");
    postOrder(t, 0);
    puts("");

    return 0;
}