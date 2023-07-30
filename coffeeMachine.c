#include <stdio.h>
#include <string.h>

struct MenuItem
{
    // Models each Menu Item.
    char name[20];
    int water;
    int milk;
    int coffee;
    double cost;
    int item_num;
};

void fillMenue(struct MenuItem *menu)
{

    strcpy(menu[0].name, "Latte");
    menu[0].water = 200;
    menu[0].milk = 150;
    menu[0].coffee = 30;
    menu[0].cost = 20;
    menu[0].item_num = 0;

    strcpy(menu[1].name, "Espresso");
    menu[1].water = 50;
    menu[1].milk = 0;
    menu[1].coffee = 20;
    menu[1].cost = 10;
    menu[1].item_num = 1;

    strcpy(menu[2].name, "Cappuccino");
    menu[2].water = 250;
    menu[2].milk = 50;
    menu[2].coffee = 60;
    menu[2].cost = 30;
    menu[2].item_num = 2;
};

int findDrink(struct MenuItem *menu, int choice)
{
    // Searches the menu for a particular drink by name. Returns that item if it exists, otherwise returns None
    for (int i = 0; i < 3; i++)
    {
        if (menu[i].item_num == choice)
        {
            return 1;
        }
    }

    printf("\n\n\n=> PLEASE ENTER VALID NUMBER TO SELECT DRINK <=\n\n\n");
    return 0;
}

void showMenu(struct MenuItem *menu)
{
    printf("\n\n\n--------------------");
    printf("\n       *MENU*\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n %d -> %s [%.2f LKR]", i + 1, menu[i].name, menu[i].cost);
        printf("\n");
    }
    printf("\n--------------------");
}

int checkResource(struct MenuItem *menu, int itemNum, int *resources)
{

    int canMake = 1;

    if ((menu[itemNum].water <= resources[0]) && (menu[itemNum].milk <= resources[1]) && (menu[itemNum].coffee <= resources[2]))
    {
        return canMake;
    }
    else
    {
        canMake = 0;
        printf("\n\n* RESOURCES NOT ENOUGH FOR => %s<= *", menu[itemNum].name);
        printf("\nYou can try another drink :-) ");
        return canMake;
    }
}

void resourceDecreaser(struct MenuItem *menu, int itemNum, int *resources)
{
    resources[0] = resources[0] - menu[itemNum].water;
    resources[1] = resources[1] - menu[itemNum].milk;
    resources[2] = resources[2] - menu[itemNum].coffee;
}

int cashier(struct MenuItem *menu, int itemNum, float *moneyBox, int *resources)
{
    int balance;
    float payment;
    printf("Please enter money(LKR) -: ");
    scanf("%f", &payment);

    if (payment >= menu[itemNum].cost)
    {
        *moneyBox = *moneyBox + menu[itemNum].cost;

        float balance = payment - menu[itemNum].cost;
        // need to add resource decreaser

        resourceDecreaser(menu, itemNum, resources);

        if (balance == 0)
        {
            printf("\n\n....... HERE IS YOUR => %s ENJOY .......\n\n", menu[itemNum].name);
            return 1;
        }
        else
        {
            printf("\nHere is your balance %.2f LKR ", balance);

            printf("\n\n....... HERE IS YOUR => %s .ENJOY .......", menu[itemNum].name);

            return 1;
        }
    }
    else
    {
        printf("\n=> ENTERD MONEY IS NOT SUFFICIENT <=\n");
        printf("Your money is returned.\n Here is your money %.2f LKR", payment);

        return 0;
    }
}

void giveReport(float *moneyBox, int *resources)
{
    printf("\n\n\n____________* REPORT *___________");
    printf("\n\n----------- Current stock ---------\n\n");
    printf("| Water => %d |", resources[0]);
    printf("| Milk  => %d |", resources[1]);
    printf("| Sugar => %d |", resources[2]);

    printf("\n\n--------- Current profit ---------\n\n");
    printf("|     %.2f     |", *moneyBox);
}

int main()
{
    int on = 1;
    int resources[] = {500, 400, 300}; // water,milk,coffee
    float money_box = 0;
    int choice;
    struct MenuItem menu[3];

    fillMenue(menu);

    while (on)
    { // show the menu to the customer
        showMenu(menu);

        printf("\nPlease choose a number to select drink =: ");
        scanf("%d", &choice);
        choice = choice - 1;
        // if machine repair occur owner can press specail code which is 1000 and
        // turn off the machine
        if (choice == 999)
        {
            printf("Machine is going to sleep");
            break;
        }
        else if (choice == 1999)
        {
            giveReport(&money_box, resources);
        }
        else
        {
            int itemAvailability = findDrink(menu, choice);
            // if user choose invalid item go to begining of the program
            if (itemAvailability == 0)
            {
                continue;
            }

            int canMake = checkResource(menu, choice, resources);

            if (canMake)
            {
                int cashEnhough = cashier(menu, choice, &money_box, resources);

                if (cashEnhough == 0)
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }
}
