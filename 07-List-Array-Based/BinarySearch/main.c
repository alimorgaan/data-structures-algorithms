
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int main(int argc, char const *argv[])
{
    List myList;
    createList(&myList); 
    insertOrder(10, &myList); 
    insertOrder(2, &myList); 
    insertOrder(30, &myList); 
    insertOrder(120, &myList);
    insertOrder(1, &myList);
    insertOrder(130, &myList);
    insertOrder(1100, &myList);
    insertOrder(12, &myList);
    insertOrder(115, &myList);
    LISTENTRY temp; 
    for (int i = 0; i < listSize(&myList); i++)
    {
        retrieveList(i, &temp, &myList);
        printf("%d\n", temp);
    }
    printf("--------------------------\n");
    printf("%d\n", binarySearch(130, &myList)); 
    system("pause"); 
    return 0;
}
