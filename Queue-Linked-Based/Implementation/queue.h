#define MAXQUEUE 100
#define QUEUEENTRY char

typedef struct queuenode
{
    QUEUEENTRY entry;
    QueueNode *next;
}QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void createQueue(Queue *);
void append(QUEUEENTRY element, Queue *);
void serve(QUEUEENTRY *elementPtr, Queue *);
int queueSize(Queue *);
int queueFull(Queue *);
int queueEmpty(Queue *);
void clearQueue(Queue *);
void traverseQueue(Queue *queuePtr, void (*functionPtr)(QUEUEENTRY));