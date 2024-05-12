/*
 * THIS PROGRAM IS A MARKET BASKET SEARCH ENGINE.
 *
 * INITILIZES A LIST OF COMMANDS in the form of a vector to accomodate more commands being added
 *
 * Uses AVL tree to create a searching mechanism for the key-value pair with a key being the store number-
 * & the value being the store name, register count, and every attribute about it
 *
 * Commands I can think of right now are:
 *  Search - will prompt the AVL tree to search the list (honestly we could just use a binary tree and have a binary search func.)
 *  Update - upon typing "update" respond with: "Update what store", accept either store number or name
 *  Add - self-explanatory add function
 */

#include "commands.h"
#include "avl.h"
#include "MarketBasket.h"

int main()
{
    Node* root = NULL;
    COMMANDS* list = initDefault();

    FILE* file = fopen("/home/sebastian/Desktop/MBSearch/MB.txt", "r");
    if (file) {
        // Attempt to deserialize data from file
        root = deserialize(file);
        fclose(file);
        if (root == NULL) {
            printf("No data found in file or data is corrupt. Starting with an empty tree.\n");
        }
    } else {
        printf("No data file found. Starting with an empty tree.\n");
    }

    while(program(&root, &list)); //run the program until user types "exit"

    file = fopen("/home/sebastian/Desktop/MBSearch/MB.txt", "w");
    if (file) {
        serialize(root, file);
        fclose(file);
    } else {
        perror("Failed to open file for writing");
    }


    treeDestroy(&root);
    destroy(list);
    return 0;
}


