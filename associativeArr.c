#include "associativeArr.h"

CommandMapping commands[] = {
        {"Store Number", updateStoreNum},
        {"Register Count", updateReg},
        {"Aisle Count", updateAisles},
        {"State", updateState},
        {"City/Town", updateCityTown}
};

void updateStoreNum(Node** root)
{
    int storeNum;
    printf("New Store Number: ");
    scanf("%d", &storeNum);

    (*root)->storeNum = storeNum;
    printf("Store Number Updated\n");
}

void updateReg(Node** root)
{
    int regCount;
    printf("New Register Count: ");
    scanf("%d", &regCount);

    (*root)->registerCount = regCount;
    printf("Register Count Updated\n");
}

void updateAisles(Node** root)
{
    int aisleCount;
    printf("New Aisle Count: ");
    scanf("%d", &aisleCount);

    (*root)->aisleCount = aisleCount;
    printf("Aisle Count Updated\n");
}
void updateState(Node** root)
{
    char state[255];
    printf("New State: ");
    fgets(state, sizeof(state), stdin);
    strcpy((*root)->state, state);
    printf("State Updated\n");
}

void updateCityTown(Node** root)
{
    char cityTown[255];
    printf("New City/Town: ");
    fgets(cityTown, sizeof(cityTown), stdin);
    strcpy((*root)->cityTown, cityTown);
    printf("City/Town Updated\n");
}

void trim(char *str)
{
    char *start = str;
    char *end = start + strlen(str) - 1;

    // Trim leading spaces
    while (isspace((unsigned char)*start)) start++;

    // Trim trailing spaces
    while (end > start && isspace((unsigned char)*end)) end--;

    // Set new null terminator
    *(end + 1) = 0;

    // Move trimmed string to the beginning
    if (start > str) memmove(str, start, end - start + 2);
}

void processCommand(const char* input, Node** root)
{
    char trimmedInput[256];
    strncpy(trimmedInput, input, sizeof(trimmedInput));
    trimmedInput[255] = '\0';  // Ensure null termination
    trim(trimmedInput);

    for (int i = 0; commands[i].func != NULL; i++)
    {
        if (strcasecmp(commands[i].input, trimmedInput) == 0) {
            commands[i].func(root);
            return;
        }
    }
    printf("Invalid command. Please try again.\n");
}
