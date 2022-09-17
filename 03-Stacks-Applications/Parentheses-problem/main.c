#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isOpen(char c)
{
    return (c == '(' || c == '{' || c == '[');
}
int isClosed(char c)
{
    return (c == ')' || c == '}' || c == ']');
}
int isMatch(char opened, char closed)
{
    return (((closed - opened) == 1) || ((closed - opened) == 2));
}
int main()
{
    Stack myStack;
    createStack(&myStack);
    while (1)
    {
        char currentChar;
        scanf("%c", &currentChar);
        if (currentChar == '\n')
        {
            printf("\nexpressin valid\n");
            break;
        }
        if (isOpen(currentChar))
        {
            push(currentChar, &myStack);
        }
        else
        {
            if (isClosed(currentChar))
            {
                char opendChar;
                if (stackEmpty(&myStack))
                {
                    printf("\nexpression not valid\n");
                    break;
                }
                pop(&opendChar, &myStack);
                if (!isMatch(opendChar, currentChar))
                {
                    printf("\nexpression not valid\n");
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}
