#ifndef MBSEARCH_ASSOCIATIVEARR_H
#define MBSEARCH_ASSOCIATIVEARR_H

#include "avl.h"
#include <ctype.h>

void trim(char *str);

void updateStoreNum(Node** root);

void updateReg(Node** root);

void updateAisles(Node** root);

void updateState(Node** root);

void updateCityTown(Node** root);

void processCommand(const char* input, Node** root);

typedef void (*updateFunctions)(Node**);

typedef struct commandMapping CommandMapping;
struct commandMapping
{
    char input[255];
    updateFunctions func;
};

#endif //MBSEARCH_ASSOCIATIVEARR_H
