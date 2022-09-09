#define MAXQUEUE 100
#define QUEUEENTRY char 

typedef struct queue
{
    int front; 
    int rear;
    int size; 
    QUEUEENTRY entry[MAXQUEUE];
}Queue;

void createQueue(Queue *);
void append(QUEUEENTRY element, Queue *);
void serve(QUEUEENTRY *elementPtr, Queue *);
int queueSize(Queue *);
int queueFull(Queue *);
int queueEmpty(Queue *);
void clearQueue(Queue *);
void traverseQueue(Queue *queuePtr, void (*functionPtr) (QUEUEENTRY)); 