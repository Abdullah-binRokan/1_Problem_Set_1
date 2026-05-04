// When customer gives you $1.00 for item costs $0.40
// Show minmmum nummber of coins to pay their change e.g., 3
/*  
    Apply Greedy Algorithms to minimize numbers of coins
    In cashier’s drawer are quarters, dimes, nickels and pennies 
    Think of greedy who wants to take the biggest bite out of this problem
*/

#include <cs50.h>
#include <stdio.h>

// define function prototype
int min_number_coins(int change_owed);

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    printf("%i\n", min_number_coins(change_owed));
}


int min_number_coins(int change_owed)
{
    // initilize coins as constant -TODO refactor to struct or enum
    const int QUARTERS = 25, DIMES = 10, NICKELS = 5, PENNIES = 1;
    int coins_counter = 0;

    // while change_owed > 0
    while (change_owed > 0)
    {
        if (change_owed >= QUARTERS)
        {
            change_owed -= QUARTERS;
        }
        else if (change_owed >= DIMES)
        {
            change_owed -= DIMES;
        }
        else if (change_owed >= NICKELS)
        {
            change_owed -= NICKELS;
        }
        else 
        {
            change_owed -= PENNIES;
        }
        
        coins_counter++;
    }
    return coins_counter;
}
