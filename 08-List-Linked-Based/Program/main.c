#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    List myList;
    createList(&myList);

    insertList(0, 'a', &myList);

    for (int i = 0; i < 26; i++)
    {
        insertList(0, 'a' + i, &myList);
    }

    LISTENTRY temp;

    for (int i = 0; i < 26; i++)
    {
        retrieveList(i, &temp, &myList);
        printf("%c\n", temp);
    }

    int apos;
    apos = sequentialSearch('a', &myList);
    printf("----------------------------\n");
    printf("a position is : %d", apos);

    system("pause");

    return 0;
}
