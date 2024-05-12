#include "MarketBasket.h"

int program(Node** root, COMMANDS** list)
{
    char input[255];
    *root = createNode(4,2,3,"Massachusetts", "Lowell");
    for (int i = 0; i < 100; i++) {
        insert(root, createNode(rand(), 2, 3, "Maine", "Topsham"));
    }

    insert(root, createNode(8, 2, 3, "Maine", "Topsham"));

    *list = initDefault();
    append(*list, "search");
    append(*list, "update");
    append(*list, "add");

    printf("COMMAND: ");
    scanf("%s", input);
  /*  for (int i = 0; i < sizeof(input); i++)
        input[i] = tolower(input[i]);*/

    if (strcmp(input, "exit") == 0)
        return 0;

    findCommand(*list, input, *root);
    return 1;
}