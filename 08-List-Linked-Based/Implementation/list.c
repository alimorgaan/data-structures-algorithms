#include "list.h"
#include <stdlib.h>

void createList(List *listPtr)
{
    listPtr->size = 0;
    listPtr->current = NULL;
    listPtr->head = NULL;
    listPtr->currentPos = -1;
}

int listEmpty(List *listPtr)
{
    return listPtr->size == 0;
}

int listFull(List *listPtr)
{
    return 0;
}

int listSize(List *listPtr)
{
    return listPtr->size;
}

void destroyList(List *listPtr)
{
    while (listPtr->head)
    {
        listPtr->current = listPtr->head->next;
        free(listPtr->head);
        listPtr->head = listPtr->current;
    }
}

void insertList(int pos, LISTENTRY element, List *listPtr)
{

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->entry = element;
    if (pos == 0)
    {
        newNode->next = listPtr->head;
        listPtr->head = newNode;
        listPtr->current = newNode;
        listPtr->currentPos = 0;
    }
    else
    {
        if (pos <= listPtr->currentPos)
        {
            listPtr->current = listPtr->head;
            listPtr->currentPos = 0;
        }
        for (int i = listPtr->currentPos; i < pos - 1; i++)
        {
            listPtr->currentPos++;
            listPtr->current = listPtr->current->next;
        }
        newNode->next = listPtr->current->next;
        listPtr->current->next = newNode;
    }
    listPtr->size++;
}

void deleteList(int pos, LISTENTRY *element, List *listPtr)
{
    if (pos == 0)
    {
        *element = listPtr->head->entry;
        listPtr->currentPos = 0;
        listPtr->current = listPtr->head->next;
        free(listPtr->head);
        listPtr->head = listPtr->current;
    }
    else
    {
        if (pos <= listPtr->currentPos)
        {
            listPtr->current = listPtr->head;
            listPtr->currentPos = 0;
        }
        for (int i = listPtr->currentPos; i < pos - 1; i++)
        {
            listPtr->current = listPtr->current->next;
            listPtr->currentPos++;
        }

        ListNode *helperPtr = listPtr->current->next;
        *element = helperPtr->entry;
        listPtr->current->next = helperPtr->next;
        free(helperPtr);
    }

    listPtr->size--;
}
void traverseList(List *listPtr, void (*functionPtr)(LISTENTRY))
{
    listPtr->current = listPtr->head;
    listPtr->currentPos = 0;
    while (listPtr->current)
    {
        (*functionPtr)(listPtr->current->entry);
        listPtr->current = listPtr->current->next;
        listPtr->currentPos++;
    }
}
void retrieveList(int pos, LISTENTRY *element, List *listPtr)
{
    if (pos <= listPtr->currentPos)
    {
        listPtr->currentPos = 0;
        listPtr->current = listPtr->head;
    }
    for (int i = listPtr->currentPos; i < pos; i++)
    {
        listPtr->currentPos++;
        listPtr->current = listPtr->current->next;
    }
    *element = listPtr->current->entry;
}
void replaceList(int pos, LISTENTRY element, List *listPtr)
{
    if (pos <= listPtr->currentPos)
    {
        listPtr->currentPos = 0;
        listPtr->current = listPtr->head;
    }
    for (int i = listPtr->currentPos; i < pos; i++)
    {
        listPtr->currentPos++;
        listPtr->current = listPtr->current->next;
    }
    listPtr->current->entry = element;
}

int sequentialSearch(LISTENTRY element, List *listPtr)
{
    ListNode *temp = listPtr->head;
    int currentPos = 0;
    while (temp)
    {
        if (temp->entry == element)
        {
            return currentPos;
        }
        currentPos++; 
        temp = temp->next; 
    }
    return -1; 
}