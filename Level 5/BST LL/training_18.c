#include "def/def.h"

int main(void) {
    bst T;
    init(&T);
    data D={100, 20, 500, 10, 30, 40};
    populate(D, &T);

    puts("Preorder Traversal:");
    preOrder(T);
    puts("");
    puts("Inorder Traversal:");
    inOrder(T);
    puts("");
    puts("Postorder Traversal:");
    postOrder(T);
    
    printf("\n\n");

    deleteData(20, &T);
    puts("Updated Preorder Traversal:");
    preOrder(T);
    puts("");


    return 0;
}