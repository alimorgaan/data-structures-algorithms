#include <stdlib.h>
#include "stack.h"

void createStack(Stack *stackPtr)
{
    stackPtr->top = NULL;
    stackPtr->size = 0;
}

void push(STACKENTRY element, Stack *stackPtr)
{
    StackNode *myNode = (StackNode *)malloc(sizeof(StackNode));
    myNode->entry = element;
    myNode->next = stackPtr->top;
    stackPtr->top = myNode;
    stackPtr->size++;
}

void pop(STACKENTRY *elementPtr, Stack *stackPtr)
{
    StackNode *helperPtr;
    helperPtr = stackPtr->top;
    *elementPtr = stackPtr->top->entry;
    stackPtr->top = stackPtr->top->next;
    free(helperPtr);
    stackPtr->size--;
}
void clearStack(Stack *stackPtr)
{
    StackNode *helperPtr;
    helperPtr = stackPtr->top;
    while (helperPtr)
    {
        helperPtr = helperPtr->next;
        free(stackPtr->top);
        stackPtr->top = helperPtr;
    }
    stackPtr->size = 0;
}

int stackSize(Stack *stackPtr)
{
    return stackPtr->size;
}
int stackFull(Stack *stackPtr)
{
    return 0;
}
int stackEmpty(Stack *stackPtr)
{
    return stackPtr->top == NULL;
}
int stackTop(STACKENTRY *elementPtr, Stack *stackPtr)
{
    *elementPtr = stackPtr->top->entry;
}

void copyStack(Stack *srcStackPtr, Stack *desStackPtr)
{
    StackNode *hSrc = srcStackPtr->top;
    clearStack(desStackPtr);
    push(hSrc->entry, desStackPtr);
    StackNode *hDes = desStackPtr->top;
    hSrc = hSrc->next;
    while (hSrc)
    {
        StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
        newNode->entry = hSrc->entry;
        newNode->next = NULL;
        hDes->next = newNode;
        hSrc = hSrc->next;
        hDes = hDes->next;
    }
    desStackPtr->size = srcStackPtr->size;
}

void traverseStack(Stack *stackPtr, void (*funcPtr)(STACKENTRY))
{
    StackNode *helperPtr;
    helperPtr = stackPtr->top;
    while (helperPtr)
    {
        (*funcPtr)(helperPtr->entry);
        helperPtr = helperPtr->next;
    }
}