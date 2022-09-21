#include "list.h"

void createList(List *listPtr)
{
    listPtr->size = 0;
}
int listEmpty(List *listPtr)
{
    return !listPtr->size;
}
int listFull(List *listPtr)
{
    return listPtr->size == MAXLIST;
}
int listSize(List *listPtr)
{
    return listPtr->size;
}
void destroyList(List *listPtr)
{
    listPtr->size = 0;
}
void insertList(int pos, LISTENTRY element, List *listPtr)
{
    for (int i = listPtr->size - 1; i >= pos; i--)
    {
        listPtr->entry[i + 1] = listPtr->entry[i];
    }
    listPtr->entry[pos] = element;
    listPtr->size++;
}

void deleteList(int pos, LISTENTRY *element, List *listPtr)
{
    *element = listPtr->entry[pos];
    for (int i = listPtr->size - 1; i > pos; i--)
    {
        listPtr->entry[i - 1] = listPtr->entry[i];
    }
    listPtr->size--;
}
void traverseList(List *listPtr, void (*functionPtr)(LISTENTRY))
{
    for (int i = 0; i < listPtr->size; i++)
    {
        (*functionPtr)(listPtr->entry[i]);
    }
}
void retrieveList(int pos, LISTENTRY *element, List *listPtr)
{
    *element = listPtr->entry[pos];
}
void replaceList(int pos, LISTENTRY element, List *listPtr)
{
    listPtr->entry[pos] = element;
}

int sequentialSearch(LISTENTRY element, List *listPtr)
{
    for (int i = 0; i < listPtr->size; i++)
    {
        if (element == listPtr->entry[i])
        {
            return i;
        }
    }
    return -1;
}

void insertOrder(LISTENTRY element, List *listPtr)
{
    int i = 0;

    for (; i < listPtr->size; i++)
        if (element <= listPtr->entry[i])
            break;

    insertList(i, element, listPtr);
}

int binarySearch(LISTENTRY element, List *listPtr)
{
    int bottom = 0;
    int top = listPtr->size - 1;
    int center;
    while (bottom < top)
    {
        center = (bottom + top) / 2;
        if (element == listPtr->entry[center])
        {
            return center;
        }
        else if (element > listPtr->entry[center])
        {
            bottom = center + 1; 
        }
        else 
        {
            top = center - 1; 
        }
    }
    return -1; 
}