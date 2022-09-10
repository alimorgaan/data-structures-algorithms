#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "queue.h"
#include "stack.h"

int menu();
void stringInput();
void displayCustomer(Customer);
void pushToStack(Customer);

// globals----------
Queue myQueue;
Stack myStack;
//------------------
int main()
{

    Customer myCustomer;

    createQueue(&myQueue);
    createStack(&myStack);

    while (1)
    {
        system("cls");
        int choise = menu();
        switch (choise)
        {
        case 1:
            system("cls");
            if (!queueFull(&myQueue))
            {
                printf("----------------------Adding a New Customer----------------------\n");
                printf("enter customer name : ");
                fflush(stdin);
                stringInput(myCustomer.name);
                printf("-------------------------------------------------------------------\n");
                printf("enter customer id : ");
                fflush(stdin);
                scanf("%d", &myCustomer.id);
                printf("-------------------------------------------------------------------\n");
                printf("enter customer model year : ");
                fflush(stdin);
                scanf("%d", &myCustomer.modelYear);
                append(myCustomer, &myQueue);
            }
            else
            {
                printf("queue is full !! \n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            if (!queueEmpty(&myQueue))
            {
                printf("----------------------Serving a Customer----------------------\n");
                serve(&myCustomer, &myQueue);

                printf("customer name : %s \n", myCustomer.name);
                printf("customer id : %d \n", myCustomer.id);
                printf("customer model year : %d \n", myCustomer.modelYear);
                system("pause");
            }
            else
            {
                printf("queue is empty !! \n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            if (!queueEmpty(&myQueue))
            {

                printf("We have %d waiting customers \n", queueSize(&myQueue));
                system("pause");
            }
            else
            {
                printf("queue is empty !! \n");
                system("pause");
            }
            break;
        case 4:
            system("cls");
            printf("------------------Customers Informations------------------\n");
            traverseQueue(&myQueue, &displayCustomer);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("------------------Customers Informations in most recent order------------------\n");
            traverseQueue(&myQueue, &pushToStack);
            traverseStack(&myStack, &displayCustomer);
            clearStack(&myStack);
            system("pause");
            break;
        case 6:
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
    printf("1-Add a New Customer\n");
    printf("2-Serve a Customer \n");
    printf("3-How many Customers Are waiting ? \n");
    printf("4-Display Customers Information\n");
    printf("5-Display Customers Information In Most-Recent Order\n");
    printf("6-Exit\n");
    int choise;
    scanf("%d", &choise);
    return choise;
}

void displayCustomer(Customer myCustomer)
{
    printf("-----------------------------------------------\n");
    printf("customer name : %s\n", myCustomer.name);
    printf("customer id : %d\n", myCustomer.id);
    printf("customer name : %d\n", myCustomer.modelYear);
    printf("-----------------------------------------------\n");
}

void pushToStack(Customer myCustomer)
{
    push(myCustomer, &myStack);
}

void stringInput(char *string)
{
    char c = getchar();
    int index = 0;
    while (!(c == '\n' || c == '\0'))
    {
        string[index] = c;
        c = getchar();
        index++;
    }
    string[index] = '\0';
}
