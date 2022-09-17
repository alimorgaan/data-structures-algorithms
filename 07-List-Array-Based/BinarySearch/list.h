#define LISTENTRY int
#define MAXLIST 100

typedef struct list
{
    int size;
    LISTENTRY entry[MAXLIST];
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
int sequentialSearch(LISTENTRY, List *);
void insertOrder(LISTENTRY, List *);