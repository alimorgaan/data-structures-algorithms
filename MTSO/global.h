#ifndef GLOBAL_H
#define GLOBAL_H
#include<stdbool.h>
typedef struct data
{
    long int callingParty; 
    long int calledParty;
    int packetSize; 
}Data;

typedef struct emergency
{
    long int callingParty; 
    long int calledParty;
}Emergency;

typedef struct voice
{
    long int callingParty; 
    long int calledParty;
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