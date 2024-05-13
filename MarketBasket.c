#include "MarketBasket.h"

int program(Node** root, COMMANDS** list)
{
    char input[255];

    if (root == NULL) {
        printf("No existing data. Use 'add' to insert new entries.\n");
    }

    append(*list, "search");
    append(*list, "update");
    append(*list, "add");
    append(*list, "remove");
    append(*list, "list all");

    printf("COMMAND: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    trimString(input);
    //scanf("%s", input);

    if (strcasecmp(input, "exit") == 0)
        return 0;
    else if (strcasecmp(input, "clear") == 0)
        system("clear");
    else if (strcasecmp(input, "help") == 0)
    {
        printf("\nCommands:\n");
        printElement((*list));
        printf("\n");
    }

    findCommand(*list, input, root);

    return 1;
}

void trimString(char* str)
{
    int length = strlen(str);
    char* front = str;
    char* end = NULL;

    if (length == 0) return;
    end = str + length - 1;
    while (end > str && isspace((unsigned char)* end))
    {
        *end = '\0';
        end--;
    }
    while (*front && isspace((unsigned char)*front))
        front++;

    if (front != str)
        memmove(str, front, (end - front) + 2);
}