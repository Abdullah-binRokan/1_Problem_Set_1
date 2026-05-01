// Division with ints, Demonstrating Truncation (discarding decimal portion)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Whats is x: ");        // 7
    int y = get_int("Whats is y: ");        // 2

    printf("x divided by y = %i\n", x / y); // gives 3 insted of 3.5
}