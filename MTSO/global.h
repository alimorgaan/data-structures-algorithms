#ifndef GLOBAL_H
#define GLOBAL_H

#include<stdbool.h>
typedef struct data
{
    char callingParty[50]; 
    char calledParty[50];
    int packetSize; 
}Data;


typedef struct emergency
{
    char callingParty[50]; 
    char calledParty[50];
}Emergency;


typedef struct voice
{
    char callingParty[50]; 
    char calledParty[50];
    bool showCaller;
    bool roaming; 
}Voice;


typedef struct call
{
    char callType; 
    union
    {
        Data data;
        Emergency emergency;
        Voice voice;
    }info;
}Call;

typedef Call LISTENTRY; 

#endif