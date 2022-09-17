#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int menu();

// function to get a copy of the stack written in the user level
//  assuming other functions are avaliable in the implementation level
void stackTopUser(STACKENTRY *, Stack *);

// function to get the size of the stack written in the user level
//  assuming other functions are avaliable in the implementation leve
int stackSizeUser(Stack *);

//function that takes stackentry and print it
//we will pass this function to traverse stack function 
void display(STACKENTRY);

int main()
{
    Stack myStack;


    STACKENTRY element;

    createStack(&myStack);

    while (1)
    {
        system("cls");
        int choise = menu();
        switch (choise)
        {
        case 1:
            clearStack(&myStack);
            break;
        case 2:
            system("cls");
            if (!stackFull(&myStack))
            {
                printf("enter a character to push : ");
                fflush(stdin);
                scanf("%c", &element);
                push(element, &myStack);
            }
            else
            {
                printf("stack is full !! \n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            if (!stackEmpty(&myStack))
            {
                printf("------------------------------------\n");
                pop(&element, &myStack);
                printf("popped element : %c \n", element);
                printf("------------------------------------\n");
                system("pause");
            }
            else
            {
                printf("stack is empty !! \n");
                system("pause");
            }

            break;
        case 4:
            system("cls");
            printf("------------------------------------\n");
            printf("Stack size is : %d \n", stackSizeUser(&myStack));
            printf("------------------------------------\n");
            system("pause");
            break;
        case 5:
            system("cls");
            if (!stackEmpty(&myStack))
            {
                printf("------------------------------------\n");
                stackTopUser(&element, &myStack);
                printf("copied element : %c \n", element);
                printf("------------------------------------\n");
                system("pause");
            }
            else
            {
                printf("stack is empty !! \n");
                system("pause");
            }

            break;
        case 6:
            if (!stackEmpty(&myStack))
            {
                traverseStack(&myStack, &display); 
                system("pause");
            }
            else
            {
                printf("stack is empty !! \n");
                system("pause");
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}

int menu()
{
    printf("1-Clear the stack \n");
    printf("2-push to the stack \n");
    printf("3-pop an element and display it\n");
    printf("4-what is the stack size\n");
    printf("5-get a copy of the top-element \n");
    printf("6-Traverse Stack\n");
    printf("7-Exit\n");
    int choise;
    scanf("%d", &choise);
    return choise;
}

void stackTopUser(STACKENTRY *elementPtr, Stack *stackPtr)
{
    pop(elementPtr, stackPtr);
    push(*elementPtr, stackPtr);
}

int stackSizeUser(Stack *stackPtr)
{
    STACKENTRY tempArray[MAXSTACK];
    int counter = 0;
    // pop all elements in temp array starting from index 0
    while (!stackEmpty(stackPtr))
    {
        pop(&tempArray[counter], stackPtr);
        counter++;
    }
    // now counter = size (last index + 1);
    // start from counter-1 to 0 push again
    for (int i = counter - 1; i >= 0; i--)
    {
        push(tempArray[counter], stackPtr);
    }
    return counter;
}

void display(STACKENTRY element)
{
    printf("%c\n", element);
}
