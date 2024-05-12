#include "avl.h"

int getHeight(Node* node);
void updateHeight(Node* node);

Node* createNode(int storeNum, int registerCount, int aisleCount, const char* state, const char* cityTown)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Build tree function says: newNode creation = NULL\n");
        return NULL;
    }

    //initializing all attributes
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->storeNum = storeNum;
    newNode->registerCount = registerCount;
    newNode->aisleCount = aisleCount;
    newNode->height = 1;

    newNode->state = (char*)malloc(strlen(state) + 1);
    if (newNode->state == NULL)
    {
        printf("Build tree function says: state string alloc = NULL\n");
        free(newNode);
        newNode = NULL;
        return NULL;
    }
    strcpy(newNode->state, state);

    newNode->cityTown = (char*)malloc(strlen(cityTown) + 1);
    if (newNode->cityTown == NULL)
    {
        printf("Build tree function says: city/town string alloc = NULL\n");
        free(newNode->state);
        newNode->state = NULL;
        free(newNode);
        newNode = NULL;
        return NULL;
    }
    strcpy(newNode->cityTown, cityTown);

    return newNode;
}

void insert(Node** root, Node* newNode)
{
    if (newNode == NULL)
    {
        printf("insertion function says: newNode to add = NULL\n");
        return;
    }

    if ((*root) == NULL)
    {
        *root = newNode;
        return;
    }

    //recursively inserting into the Binary Tree
    if (newNode->storeNum < (*root)->storeNum)
        insert(&((*root)->left), newNode);
    else if (newNode->storeNum > (*root)->storeNum)
        insert(&((*root)->right), newNode);
    else
        return;

    updateHeight(*root);

    //Maintaining AVL balance properties
    int balanceFactor = getHeight((*root)->right) - getHeight((*root)->left);
    if (balanceFactor > 1)
    {
        if (getHeight((*root)->right->left) > getHeight((*root)->right->right))
            rightRotation(&((*root)->right));
        leftRotation(root);
    }
    else if (balanceFactor < -1)
    {
        if (getHeight((*root)->left->right) > getHeight((*root)->left->left))
            leftRotation(&((*root)->left));
        rightRotation(root);
    }
}

void inorderPrint(Node* root)
{
    if (root == NULL)
        return;
    //inorderPrint(root->left);
    printf("Store Number: %d\n", root->storeNum);
    printf("Register Count: %d\n", root->registerCount);
    printf("Aisle Count: %d\n", root->aisleCount);
    printf("State: %s\n", root->state);
    printf("City/Town: %s\n", root->cityTown);
    printf("\n");
    //inorderPrint(root->right);
}

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

void rightRotation(Node** pNode)
{
    Node* root = *pNode;
    Node* newRoot = (*pNode)->left;
    root->left = newRoot->right;
    newRoot->right = root;
    *pNode = newRoot;
    updateHeight(root);
    updateHeight(newRoot);
}

void leftRotation(Node** pNode)
{
    Node* root = *pNode;
    Node* newRoot = (*pNode)->right;
    root->right = newRoot->left;
    newRoot->left = root;
    *pNode = newRoot;
    updateHeight(root);
    updateHeight(newRoot);
}

void search(Node* root, int storeNum)
{
    if (root == NULL)
        return;

    if (root->storeNum == storeNum)
    {
        inorderPrint(root);
        return;
    }

    if (storeNum > root->storeNum)
        search(root->right, storeNum);
    else
        search(root->left, storeNum);
}

void treeDestroy(Node** root)
{
    if (*root == NULL)
        return;

    treeDestroy(&((*root)->right));
    treeDestroy(&((*root)->left));
    free((*root)->state);
    (*root)->state = NULL;
    free((*root)->cityTown);
    (*root)->cityTown = NULL;
    free(*root);
    *root = NULL;
}

int getHeight(Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void updateHeight(Node* node)
{
    if (node != NULL) {
        node->height = 1 + findMax(getHeight(node->left), getHeight(node->right));
    }
}

//GPT GENERATED FUNCTION FOR AVL VERIFICATION
void printTree(Node* root, int space)
{
    int i;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->storeNum);

    // Process left child
    printTree(root->left, space);
}

