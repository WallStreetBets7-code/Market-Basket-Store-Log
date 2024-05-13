#include "commands.h"

void clearKeyboardBuffer();

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

    if (strcasecmp(input, pList->cmd[0]) == 0)
    {
        // Search function
        printf("Search Store Number: ");
        scanf("%d", &searchNum);
        getchar();
        printf("\n");
        Node* temp = search(*root, searchNum);
        printNode(temp);
    }
    else if (strcasecmp(input, pList->cmd[1]) == 0)
    {
        //update function
        char in[255];
        int storeNum;
        //update attribute function
        printf("\n");
        printf("Update Which Store?: ");
        scanf("%d", &storeNum);
        printf("Update What?\n"
               "Store Number\n"
               "Register Count\n"
               "Aisle Count\n"
               "State\n"
               "City/Town\n"
               ": ");
        getchar();
        fgets(in, sizeof(in), stdin);
        Node* target = search(*root, storeNum);
        processCommand(in, &target);
    }
    else if (strcasecmp(input, pList->cmd[2]) == 0)
    {
        // Add function
        int storeNum, regCount, aisleCount;
        char state[255], cityTown[255];

        printf("Store Number: ");
        scanf("%d", &storeNum);
        clearKeyboardBuffer();

        printf("Register Count: ");
        scanf("%d", &regCount);
        clearKeyboardBuffer();

        printf("Aisle Count: ");
        scanf("%d", &aisleCount);
        clearKeyboardBuffer();

        printf("State: ");
        fgets(state, sizeof(state), stdin);
        state[strcspn(state, "\n")] = 0;

        printf("City/Town: ");
        fgets(cityTown, sizeof(cityTown), stdin);
        cityTown[strcspn(cityTown, "\n")] = 0;

        Node* newNode = createNode(storeNum, regCount, aisleCount, state, cityTown);
        insert(root, newNode);
        printf("\n");
    }
    /*else if (strcasecmp(input, pList->cmd[3]) == 0)
    {
        //remove function

    }*/
    else if (strcasecmp(input, pList->cmd[4]) == 0)
    {
        //list all function
        inorderPrint(*root);
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

void clearKeyboardBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
}



