#define STACKENTRY char

typedef struct stacknode
{
    STACKENTRY entry; 
    struct stacknode * next ; 
}StackNode;

typedef struct stack
{
    StackNode *top;
    unsigned int size ;
}Stack;


void createStack(Stack *);
void push(STACKENTRY, Stack *);
void pop(STACKENTRY *, Stack *);
void clearStack(Stack *);
int stackSize(Stack *);
int stackFull(Stack *);
int stackEmpty(Stack *);
int stackTop(STACKENTRY *, Stack *);
void copyStack(Stack *srcStackPtr, Stack *desStackPtr);
void traverseStack(Stack * , void (*funcPtr)(STACKENTRY)); 