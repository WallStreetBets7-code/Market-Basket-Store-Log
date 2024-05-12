#ifndef MBSEARCH_AVL_H
#define MBSEARCH_AVL_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node
{
    int storeNum; //this will be the key
    int registerCount;
    int aisleCount;
    char* state;
    char* cityTown;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int storeNum, int registerCount, int aisleCount, const char* state, const char* cityTown);
void insert(Node** root, Node* newNode);
void treeDestroy(Node** root);
void inorderPrint(Node* root);
int getHeight(Node* root);
int findMax(int a, int b);
void rightRotation(Node** pNode);
void leftRotation(Node** pNode);
void printTree(Node* root, int space);
void search(Node* root, int storeNum);

//to store previous data
void serialize(Node* root, FILE* fp);
Node* deserialize(FILE* fp);

#endif //MBSEARCH_AVL_H
