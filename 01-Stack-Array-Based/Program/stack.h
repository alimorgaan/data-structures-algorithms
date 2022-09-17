#define MAXSTACK 100
#define STACKENTRY char

typedef struct stack
{
    STACKENTRY entry[MAXSTACK];
    int top;
} Stack;

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