#include "tree.h"
#include <stdlib.h>

void createTree(Tree *treePtr)
{
    treePtr->root = NULL;
    treePtr->size = 0;
}

void clearTreeAux(TreeNode *root)
{
    if (root)
    {
        clearTreeAux(root->left);
        clearTreeAux(root->right);
        free(root);
    }
}

void clearTree(Tree *treePtr)
{
    clearTreeAux(treePtr->root);
    treePtr->root = NULL;
    treePtr->size = 0;
}

void inOrderAux(TreeNode *root, void (*functionPtr)(TREEENTRY))
{
    if (root)
    {
        inOrderAux(root->left, functionPtr);
        (*functionPtr)(root->entry);
        inOrderAux(root->right, functionPtr);
    }
}

void inOrder(Tree *treePtr, void (*functionPtr)(TREEENTRY)) // LVR
{
    inOrderAux(treePtr->root, functionPtr);
}

void insertTree(Tree *treePtr, TREEENTRY *elementPtr)
{
    TreeNode *parentPtr;
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->entry = *elementPtr;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *helperPtr;
    parentPtr = NULL;
    helperPtr = treePtr->root;

    while (helperPtr)
    {
        if (*elementPtr >= helperPtr->entry)
        {
            parentPtr = helperPtr;
            helperPtr = helperPtr->right;
        }
        else
        {
            parentPtr = helperPtr;
            helperPtr = helperPtr->left;
        }
    }

    if (parentPtr)
    {
        if (*elementPtr >= parentPtr->entry)
            parentPtr->right = newNode;
        else
            parentPtr->left = newNode;
    }
    else
    {
        treePtr->root = newNode;
    }

    treePtr->size++;
}

int treeSize(Tree *treePtr)
{
    return treePtr->size;
}

int findItemTree(Tree *treePtr, TREEENTRY target)
{
    int found = 0;
    TreeNode *helperPtr = treePtr->root;
    while (!found && helperPtr)
    {
        if (target > helperPtr->entry)
            helperPtr = helperPtr->right;
        else if (target < helperPtr->entry)
            helperPtr = helperPtr->right;
        else
            found = 1;
    }
    if (found)
        return 1;
    else
        return 0;
}

void deleteNode(TreeNode **nodePtr)
{
    TreeNode *temp = *nodePtr;
    if (!(*nodePtr)->left)
    {
        (*nodePtr) = (*nodePtr)->right;
        free(temp);
    }
    else if (!(*nodePtr)->right)
    {
        (*nodePtr) = (*nodePtr)->left;
        free(temp);
    }
    else
    {
        TreeNode *helperPtr = temp->left;
        if (!helperPtr->right)
        {
            temp->entry = helperPtr->entry;
            temp->left = helperPtr->left;
            free(helperPtr);
        }
        else
        {
            TreeNode *helperPtr = temp->left;
            TreeNode *parent;
            while (helperPtr->right)
            {
                parent = helperPtr;
                helperPtr = helperPtr->right;
            }
            temp->entry = helperPtr->entry;
            parent->right = helperPtr->left;
            free(helperPtr);
        }
    }
}

void deleteItemTree(Tree *treePtr, TREEENTRY target)
{
    TreeNode *parent = NULL;
    TreeNode *helperPtr = treePtr->root;
    int found = 0;
    while (!found && helperPtr)
    {
        if (target > helperPtr->entry)
        {
            parent = helperPtr;
            helperPtr = helperPtr->right;
        }
        else if (target < helperPtr->entry)
        {
            parent = helperPtr;
            helperPtr = helperPtr->left;
        }
        else
            found = 1;
    }
    if (found)
    {
        if (!parent)
            deleteNode(&treePtr->root);
        else if (target >= parent->entry)
            deleteNode(&parent->right);
        else
            deleteNode(&parent->left);
    }
}