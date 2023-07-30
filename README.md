# Coffee Machine Readme

## Description

This is a simple C code for a coffee machine. The coffee machine offers three types of coffee: cappuccino, latte, and espresso. Customers can enter money and select their desired coffee type, and the machine will dispense the coffee accordingly.

## Usage

1. The program will prompt the customer to enter the coffee type (1 for cappuccino, 2 for latte, and 3 for espresso).
2. Next, the customer can enter the amount of money they want to insert to purchase the coffee.
3. If the entered amount is sufficient, the coffee will be dispensed, and the change (if any) will be returned to the customer.
4. If the entered amount is not sufficient, the transaction will be canceled, and the money will be returned to the customer. The customer will then be redirected to the menu to try again.

## Owner's Report

The owner of the machine can get a report of the current resource status , current profit of the coffee machine by using code 2000 as input.

## Turning Off the Machine

If the owner wants to turn off the coffee machine, they can press 1000.

## Note

Please ensure that you have a C compiler installed on your system to run this program. You can compile and execute the code using the following commands:

```bash
gcc coffeeMachine.c -o coffeeMachine
./coffeeMachine
```

This will compile the `coffeeMachine.c` source file and create an executable named `coffeeMachine`. Running `./coffeeMachine` will start the coffee machine program.

## Important Notices

1. **Resource Over Warning**: If the resources of the coffee machine (e.g., coffee beans, milk, water) are depleted, the machine will not be able to grant coffee to the customers. In such cases, a warning message will be displayed, informing the customer that the resources of the machine are over. The customer will then be redirected to the main menu.

2. **Invalid Selection Warning**: If the customer chooses a number that does not correspond to any of the available coffee types, a warning message will be displayed. The customer will be directed back to the main menu to make a valid selection.

3. **Exiting the Program**: To exit the program, the user (customer or owner) can press `Ctrl+C` in the terminal or follow the standard procedure to terminate a program execution in their operating system.

Please enjoy your coffee experience with the coffee machine! If you have any questions or encounter any issues, feel free to contact the developer. Happy coffee brewing!
