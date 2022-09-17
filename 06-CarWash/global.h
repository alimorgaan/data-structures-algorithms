#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct customer
{
    char name[50];
    int id;
    int modelYear;
} Customer;

typedef Customer STACKENTRY;
typedef Customer QUEUEENTRY;

#endif
