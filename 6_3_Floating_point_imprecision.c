// Floating point imprecision 
// There are limits to how precise computers can calculate numbers
/*
    %.50f to display up to 50 decimal places, revealing the limitations 
    of floating-point precision as the result may show unexpected 
    digits due to binary representation constraints
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("What's x? ");
    float y = get_float("What's y? ");

    printf("%.50f\n", x / y);
}
