#ifndef MBSEARCH_MARKETBASKET_H
#define MBSEARCH_MARKETBASKET_H

#include "avl.h"
#include "commands.h"
#include <ctype.h>

/*
 * AT THE BASIC LEVEL:
 * Ask the user to provide a command
 * do the operation on the binary tree based on that command
 */

int program(Node** root, COMMANDS** list);
void trimString(char* str);

#endif //MBSEARCH_MARKETBASKET_H
