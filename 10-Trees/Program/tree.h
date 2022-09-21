#define TREEENTRY int

typedef struct treenode
{
    TREEENTRY entry;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

typedef struct tree
{
    int size;
    TreeNode *root;
} Tree;

void createTree(Tree *);
void clearTree(Tree *);
void inOrder(Tree *, void (*functionPtr)(TREEENTRY));
void insertTree(Tree *, TREEENTRY *);
int treeSize(Tree *);
int findItemTree(Tree *, TREEENTRY);
void deleteItemTree(Tree *, TREEENTRY);