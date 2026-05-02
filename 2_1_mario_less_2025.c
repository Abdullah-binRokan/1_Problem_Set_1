#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // prompt user for height
        height = get_int("Height: ");
    }
    while (height < 1);

    printf("height is %i\n", height);
}
