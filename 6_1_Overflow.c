// Integer Overflow
/*  int takes 4 bytes (32 bits). 
    Max for negative is -2^31 = -2,147,483,648
    Max for positve is 2^31-1 = 2,147,483,647
    If you reach max it will wrap around to negative (vice versa) or Zero
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    while (true)
    {
        char c = get_char("Here's $%i. Double it for the next person? ", dollars);
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
            dollars --;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%i\n", dollars);
}