#define DATA 'D'
#define VOICE 'V'
#define EMERGENCY 'E'

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "global.h"

int menu();

int main()
{
    List myList;
    createList(&myList);
    Call myCall;

    int dataCallsCounter = 0;
    int voiceCallsCounter = 0;
    int emergencyCallsCounter = 0;

    int choice;
    while (1)
    {
        system("cls");
        choice = menu();

        switch (choice)
        {
        case 1:
            system("cls");
            myCall.callType = DATA;
            printf("---------Data Call Coming---------------\n\n");
            printf("Enter calling party number : ");
            scanf("%d", &myCall.info.data.callingParty);
            printf("\n");
            printf("Enter called party number : ");
            scanf("%d", &myCall.info.data.calledParty);
            printf("\n");
            printf("Enter number of packets : ");
            scanf("%d", &myCall.info.data.packetSize);
            printf("\n");
            insertList(listSize(&myList), myCall, &myList);
            dataCallsCounter++;
            break;
        case 2:
            system("cls");
            myCall.callType = VOICE;
            printf("---------Voice Call Coming---------------\n\n");
            printf("Enter calling party number : ");
            scanf("%d", &myCall.info.voice.callingParty);
            printf("\n");
            printf("Enter called party number : ");
            scanf("%d", &myCall.info.voice.calledParty);
            printf("\n");
            printf("To show caller id enter 1 , to hide enter 0  : ");
            scanf("%d", &myCall.info.voice.showCaller);
            printf("\n");
            printf("for roaming call enter 1 , no roaming enter 0  : ");
            scanf("%d", &myCall.info.voice.roaming);
            printf("\n");
            insertList(emergencyCallsCounter + voiceCallsCounter, myCall, &myList);
            voiceCallsCounter++;
            break;

        case 3:
            system("cls");
            myCall.callType = EMERGENCY;
            printf("---------Emergency Call Coming---------------\n\n");
            printf("Enter calling party number : ");
            scanf("%d", &myCall.info.emergency.callingParty);
            printf("\n");
            printf("Enter called party number : ");
            scanf("%d", &myCall.info.emergency.calledParty);
            printf("\n");
            insertList(emergencyCallsCounter, myCall, &myList);
            emergencyCallsCounter++;
            break;

        case 4:
            system("cls");
            if (!listEmpty(&myList))
            {
                deleteList(0, &myCall, &myList);
                switch (myCall.callType)
                {
                case DATA:
                    printf("----------------Serving data call----------------\n\n");
                    dataCallsCounter--;
                    printf("calling party number : %d \n", myCall.info.data.callingParty);
                    printf("called party number : %d \n", myCall.info.data.calledParty);
                    printf("number of packets : %d \n", myCall.info.data.packetSize);
                    break;
                case VOICE:
                    printf("----------------Serving voice call----------------\n\n");
                    voiceCallsCounter--;
                    printf("calling party number : %d \n", myCall.info.voice.callingParty);
                    printf("called party number : %d \n", myCall.info.voice.calledParty);
                    printf("show caller : %d \n", myCall.info.voice.showCaller);
                    printf("roaming : %d \n", myCall.info.voice.roaming);
                    break;
                case EMERGENCY:
                    printf("----------------Serving emergency call----------------\n\n");
                    emergencyCallsCounter--;
                    printf("calling party number : %d \n", myCall.info.emergency.callingParty);
                    printf("called party number : %d \n", myCall.info.emergency.calledParty);
                    break;
                }
                system("pause");
            }
            else
            {
                printf("there is no calls to serve !! \n");
                system("pause");
            }
            break;
        case 5:
            if (dataCallsCounter)
            {
                for (int i = 0; i < dataCallsCounter; i++)
                {
                    deleteList(listSize(&myList) - 1, &myCall, &myList);
                }
                dataCallsCounter = 0;
            }
            else if (voiceCallsCounter)
            {
                for (int i = 0; i < voiceCallsCounter; i++)
                {
                    deleteList(listSize(&myList) - 1, &myCall, &myList);
                }
                voiceCallsCounter = 0;
            }
            break;
        case 6:
            exit(0);
            break;
        }
    }

    system("pause");
    return 0;
}

int menu()
{
    int choice;
    printf("1- Data call coming\n");
    printf("2- Voice call coming\n");
    printf("3- Emergency call coming\n");
    printf("4- Serve a call\n");
    printf("5- Dismiss calls with least priority\n");
    printf("6- Exit\n");
    scanf("%d", &choice);
    return choice;
}