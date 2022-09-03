#include "stack.h"

void createStack(Stack *stackPtr)
{
    stackPtr->top = 0;
}

void push(STACKENTRY element, Stack *stackPtr)
{
    stackPtr->entry[stackPtr->top] = element;
    stackPtr->top++;
}
void pop(STACKENTRY *elementPtr, Stack *stackPtr)
{
    *elementPtr = stackPtr->entry[stackPtr->top - 1];
    stackPtr->top--;
}
void clearStack(Stack *stackPtr)
{
    stackPtr->top = 0;
}
int stackSize(Stack *stackPtr)
{
    return stackPtr->top;
}

int stackFull(Stack *stackPtr)
{
    if (stackPtr->top == MAXSTACK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stackEmpty(Stack *stackPtr)
{
    if (stackPtr->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackTop(STACKENTRY *elementPtr, Stack *stackPtr)
{
    *elementPtr = stackPtr->entry[stackPtr->top - 1];
}

void copyStack(Stack *srcStackPtr, Stack *desStackPtr)
{
    desStackPtr->top = srcStackPtr->top;
    for (int i = 0; i < srcStackPtr->top; i++)
    {
        desStackPtr->entry[i] = srcStackPtr->entry[i];
    }
}

void traverseStack(Stack *stackPtr, void (*funcPtr)(STACKENTRY))
{
    for (int i = stackPtr->top - 1; i >= 0; i--)
    {
        (*funcPtr)(stackPtr->entry[i]);
    }
}