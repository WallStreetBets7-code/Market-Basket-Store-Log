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

int main()
{
  /*  COMMANDS list = initDefault();
    append(list, "Search");
    append(list, "Update");
    append(list, "Add");
    printElement(list);
    destroy(list);*/

    Node* root = createNode(4,2,3,"Massachusetts", "Lowell");
    for (int i = 0; i < 10; i++) {
        insert(&root, createNode(i, 2, 3, "Maine", "Topsham"));
    }
    //inorderPrint(root);
    //printTree(root, 0);
    search(root, 8);
    treeDestroy(&root);
    return 0;
}
