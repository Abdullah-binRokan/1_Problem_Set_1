// Integer Overflow
/*  int takes 4 bytes (32 bits). 
    Max for negative is -2^31 = -2,147,483,648
    Max for positve is 2^31-1 = 2,147,483,647
    If you reach max it will wrap around to negative (vice versa) or Zero
    Note: unsigned int max value is 2^32-1 (postive takes up full 4 bytes)
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    // unsigned int dollars = 4294967295;
    while (true)
    {
        char c = get_char("Here's $%i. Double it for the next person? ", dollars);
        // use %u for unsigned int
        // char c = get_char("Here's $%u. Double it for the next person? ", dollars);
        if (c == 'y')
        {
            dollars *= 2;
        }
        else if (c == '1') // to help you reach max positve value
        {
            dollars++;
        }
        else if (c == '2') // to help you wrap around from negatvie to max positive
        {
            dollars--;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%i\n", dollars);
    // printf("Here's $%u\n", dollars);  // used for unsigned int
}