#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void display(TREEENTRY element)
{
    printf("%d\n", element);
}

int main(int argc, char const *argv[])
{
    Tree myTree;
    TREEENTRY element;
    createTree(&myTree);

    element = 50;
    insertTree(&myTree, &element);

    element = 25;
    insertTree(&myTree, &element);

    element = 100;
    insertTree(&myTree, &element);

    element = 20;
    insertTree(&myTree, &element);

     element = 30;
    insertTree(&myTree, &element);

     element = 120;
    insertTree(&myTree, &element);


     element = 150;
    insertTree(&myTree, &element);

     element = 28;
    insertTree(&myTree, &element);

    deleteItemTree(&myTree, 25);
    
    inOrder(&myTree, &display);

    printf("---------------------------\n");

    printf("%d\n", findItemTree(&myTree, 2222));

    clearTree(&myTree);

    inOrder(&myTree, &display);

    system("pause");
    return 0;
}
