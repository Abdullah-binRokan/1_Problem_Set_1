#include <cs50.h>
#include <stdio.h>

// create_pyramid prototype
void create_pyramid(int height);

int main(void)
{
    int height;
    do
    {
        // prompt user for height
        height = get_int("Height: ");
    }
    while (height < 1);

    // call create_pyramid
    create_pyramid(height);
}

// define create_pyramid function
void create_pyramid(int height)
{
    // initilize row_number
    int row_number = 1;
    for (int i = 0; i < height; i++) 
    {
        // loop to print empty spaces which is (height - row_number)
        for (int space = 0; space < height - row_number; space++)
        {
            printf(" ");
        }
        // loop through row_number to print the bricks
        for (int brick = 0; brick < row_number; brick++)
        {
            printf("#");
        }
        // increment row_number
        row_number++;
        // print new line to prepare for next row
        printf("\n");
    }
}