#define LISTENTRY char

typedef struct listNode
{
    LISTENTRY entry;
    struct listNode *next;
} ListNode;

typedef struct list
{
    int currentPos;
    int size;
    ListNode *current;
    ListNode *head;
} List;

void createList(List *);
int listEmpty(List *);
int listFull(List *);
int listSize(List *);
void destroyList(List *);
void insertList(int, LISTENTRY, List *);
void deleteList(int, LISTENTRY *, List *);
void traverseList(List *, void (*functionPtr)(LISTENTRY));
void retrieveList(int, LISTENTRY *, List *);
void replaceList(int, LISTENTRY, List *);
int sequentialSearch(LISTENTRY , List *);