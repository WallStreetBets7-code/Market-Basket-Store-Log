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

    printf("COMMAND: ");
    scanf("%s", input);

    if (strcmp(input, "exit") == 0)
        return 0;

    findCommand(*list, input, root);
    return 1;
}