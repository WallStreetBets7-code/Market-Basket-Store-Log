#include "commands.h"

typedef struct commands Commands;
struct commands
{
    int size;
    int capacity;
    char** cmd;
};

boolean resize(Commands* list);

COMMANDS initDefault()
{
    int i;
    Commands* commandList = (Commands*)malloc(sizeof(Commands));
    if (commandList == NULL)
    {
        printf("Command list init = NULL\n");
        return NULL;
    }
    else
    {
        commandList->capacity = 2; //ability to hold 10 commands
        commandList->size = 0;
        commandList->cmd = malloc(commandList->capacity * sizeof(char*));
        if (commandList->cmd == NULL)
        {
            free(commandList);
            printf("Command list alloc failed\n");
            return NULL;
        }

        for (i = 0; i < commandList->capacity; i++)
            commandList->cmd[i] = NULL;

    }
    return commandList;
}

boolean append(COMMANDS hList, const char* commandType)
{
    if (hList == NULL)
    {
        printf("Opaque hList = NULL\n");
        return FALSE;
    }

    Commands* pList = (Commands*)hList; //typecast

    if (pList->size >= pList->capacity - 1)
    {
        if (resize(pList) == FALSE)
        {
            printf("Resize failed\n");
            return FALSE;
        }
    }

    //allocating memory for each array element every time this function is called
    pList->cmd[pList->size] = (char*)malloc(strlen(commandType) + 1); //getting the size of the command we want to insert
    if (pList->cmd[pList->size] == NULL)
    {
        printf("append function says: hList element allocation = NULL\n");
        return FALSE;
    }
    strcpy(pList->cmd[pList->size], commandType);
    pList->size++;
    return TRUE;
}

void printElement(COMMANDS hList)
{
    Commands* pList = (Commands*)hList; //typecast
    for (int i = 0; i < pList->size; i++)
    {
        printf("%s\n", pList->cmd[i]);
    }
}

void findCommand(COMMANDS hList, const char* input, Node** root)
{
    Commands* pList = (Commands*)hList;
    int searchNum;

    if (strcmp(input, pList->cmd[0]) == 0) { // Search function
        printf("Search Store Number: ");
        scanf("%d", &searchNum);
        printf("\n");
        search(*root, searchNum); // Now properly using the pointer to root
    }
    else if (strcmp(input, pList->cmd[2]) == 0)  // Add function
    {
        int storeNum, regCount, aisleCount;
        char state[255], cityTown[255];

        printf("Store Number: ");
        scanf("%d", &storeNum);
        printf("Register Count: ");
        scanf("%d", &regCount);
        printf("Aisle Count: ");
        scanf("%d", &aisleCount);
        printf("State: ");
        scanf("%s", state);
        printf("City/Town: ");
        scanf("%s", cityTown);

        Node* newNode = createNode(storeNum, regCount, aisleCount, strdup(state), strdup(cityTown));
        insert(root, newNode);  // Correctly attach this new node to the AVL tree
        printf("\n");
    }
}

boolean destroy(COMMANDS* hList)
{
    if (hList == NULL)
    {
        printf("Opaque hList = NULL\n");
        return FALSE;
    }

    Commands* pList = (Commands*)hList; //typecast

    //free each element
    for (int i = 0; i < pList->size; i++)
    {
        free(pList->cmd[i]);
        pList->cmd[i] = NULL;
    }

    //free the array
    free(pList->cmd);
    pList->cmd = NULL;
    //free the struct
    free(pList);
    return TRUE;
}

boolean resize(Commands* pList)
{
    if (pList == NULL)
    {
        printf("Resize function says: list = NULL\n");
        return FALSE;
    }
    else
    {
        //printf("Resizing\n");
        int newCap = pList->capacity * 2;
        char** newArr = realloc(pList->cmd, newCap * sizeof(char*));
        if (pList->cmd == NULL)
        {
            printf("Resize function says: list realloc = NULL\n");
            return FALSE;
        }
        pList->cmd = newArr;
        pList->capacity = newCap;
        return TRUE;
    }
}



