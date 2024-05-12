#ifndef MBSEARCH_COMMANDS_H
#define MBSEARCH_COMMANDS_H

#include "boolean.h"
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* COMMANDS;

COMMANDS initDefault();

boolean append(COMMANDS hList, const char* commandType);

void printElement(COMMANDS hList);

void findCommand(COMMANDS hList, const char* input, Node* root);

boolean destroy(COMMANDS* hList);

#endif //MBSEARCH_COMMANDS_H

