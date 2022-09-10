#include "queue.h"
#include <stdlib.h>

void createQueue(Queue *queuePtr)
{
    queuePtr->front = NULL;
    queuePtr->rear = NULL;
    queuePtr->size = 0;
}

void append(QUEUEENTRY element, Queue *queuePtr)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->entry = element;
    newNode->next = NULL;
    if (!queuePtr->rear)
    {
        queuePtr->front = newNode;
    }
    else
    {
        queuePtr->rear->next = newNode;
    }
    queuePtr->rear = newNode;
    queuePtr->size++;
}
void serve(QUEUEENTRY *elementPtr, Queue *queuePtr)
{
    QueueNode *helperPtr = queuePtr->front->next;
    *elementPtr = queuePtr->front->entry;
    free(queuePtr->front);
    if (!helperPtr)
    {
        queuePtr->rear = NULL;
    }
    queuePtr->front = helperPtr;
    queuePtr->size--;
}

int queueSize(Queue *queuePtr)
{
    return queuePtr->size;
}
int queueFull(Queue *queuePtr)
{
    return 0;
}
int queueEmpty(Queue *queuePtr)
{
    return queuePtr->size == 0;
}
void clearQueue(Queue *queuePtr)
{
    while (queuePtr->rear)
    {
        queuePtr->rear = queuePtr->front->next;
        free(queuePtr->front);
        queuePtr->front = queuePtr->rear;
    }
    queuePtr->size = 0;
}
void traverseQueue(Queue *queuePtr, void (*functionPtr)(QUEUEENTRY))
{
    QueueNode *helperPtr = queuePtr->front;
    while (helperPtr)
    {
        (*functionPtr)(helperPtr->entry);
        helperPtr = helperPtr->next;
    }
}