#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int menu();

void display(QUEUEENTRY);

int main()
{
    Queue myQueue;
    QUEUEENTRY element;

    createQueue(&myQueue);

    while (1)
    {
        system("cls");
        int choise = menu();
        switch (choise)
        {
        case 1:
            clearQueue(&myQueue);
            break;
        case 2:
            system("cls");
            if (!queueFull(&myQueue))
            {
                printf("enter a character to append : ");
                fflush(stdin);
                scanf("%c", &element);
                append(element, &myQueue);
            }
            else
            {
                printf("queue is full !! \n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            if (!queueEmpty(&myQueue))
            {
                printf("------------------------------------\n");
                serve(&element, &myQueue);
                printf("served element : %c \n", element);
                printf("------------------------------------\n");
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
            printf("------------------------------------\n");
            printf("queue size is : %d \n", queueSize(&myQueue));
            printf("------------------------------------\n");
            system("pause");
            break;

        case 5:
            if (!queueEmpty(&myQueue))
            {
                traverseQueue(&myQueue, &display);
                system("pause");
            }
            else
            {
                printf("queue is empty !! \n");
                system("pause");
            }
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
    printf("1-Clear the queue \n");
    printf("2-append to queue \n");
    printf("3-serve from the queue\n");
    printf("4-what is the queue size\n");
    printf("5-Traverse queue\n");
    printf("6-Exit\n");
    int choise;
    scanf("%d", &choise);
    return choise;
}

void display(QUEUEENTRY element)
{
    printf("%c\n", element);
}
