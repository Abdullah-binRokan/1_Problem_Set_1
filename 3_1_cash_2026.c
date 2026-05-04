// Customer gives you $1.00 for item costs $0.50
// Show minmmum nummber of coins to Pay their change
/*  
    Apply Greedy Algorithms to minimize numbers of coins
    In cashier’s drawer are quarters, dimes, nickels and pennies 
    Think of greedy who wants to take the biggest bite out of this problem
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    printf("%i", min_number_coins(change_owed));
}


int min_number_coins(change_owed)
{
    // initilize coins as constant -TODO refactor to struct or enum
    // while change_owed > 0
        // if change_owed > QUARTERS
            // change_owed - QUARTERS
        // else if ... 
}

