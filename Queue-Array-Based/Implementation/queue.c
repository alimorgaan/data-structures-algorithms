#include "queue.h"

void createQueue(Queue *queuePtr)
{
    queuePtr->front = 0;
    queuePtr->rear = -1;
    queuePtr->size = 0;
}
void append(QUEUEENTRY element, Queue *queuePtr)
{
    if (queuePtr->rear == MAXQUEUE - 1)
    {
        queuePtr->rear = 0;
    }
    else
    {
        queuePtr->rear++;
    }
    queuePtr->entry[queuePtr->rear] = element;
    queuePtr->size++;
}

void serve(QUEUEENTRY *elementPtr, Queue *queuePtr)
{
    *elementPtr = queuePtr->entry[queuePtr->front];
    if (queuePtr->front == MAXQUEUE - 1)
    {
        queuePtr->front = 0;
    }
    else
    {
        queuePtr->front++;
    }
    queuePtr->size--;
}
int queueSize(Queue *queuePtr)
{
    return queuePtr->size;
}
int queueFull(Queue *queuePtr)
{
    return queuePtr->size == MAXQUEUE;
}
int queueEmpty(Queue *queuePtr)
{
    return queuePtr->size == 0;
}
void clearQueue(Queue *queuePtr)
{
    queuePtr->front = 0;
    queuePtr->rear = -1;
    queuePtr->size = 0;
}
void traverseQueue(Queue *queuePtr, void (*functionPtr)(QUEUEENTRY))
{
    int pos = queuePtr->front;

    while (pos != queuePtr->rear)
    {
        (*functionPtr)(queuePtr->entry[pos]);
        if (pos == MAXQUEUE - 1)
        {
            pos = 0;
        }
        else
        {
            pos++;
        }
    }
    (*functionPtr)(queuePtr->entry[pos]);
}