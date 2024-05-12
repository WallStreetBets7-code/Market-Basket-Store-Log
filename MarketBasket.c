#include "MarketBasket.h"

void program()
{
    char input[255];
    int i = 0;

    COMMANDS list = initDefault();
    append(list, "Search");
    append(list, "Update");
    append(list, "Add");

    printf("COMMAND: ");
    scanf("%s", input);
    for (i = 0; i < sizeof(input); i++)
        input[i] = tolower(input[i]);

    findCommand(list, input);

}