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

    char temp;
    char take;
    deleteList(0 , &take , &myList); 

    for (int i = 0; i < 26; i++)
    {
        retrieveList(i, &temp, &myList);
        printf("%c\n", temp);
    }

    printf("---------------\n%c", take); 

    system("pause");

    return 0;
}
