// print mario adjacent pyramids
#include <cs50.h>
#include <stdio.h>

// create_pyramids function prototype
// print_empty function prototype
// print_bricks function prototype

int main(void)
{
    int height;
    // prompt user for input between 1 - 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // call create_pyramids function
}


// define create_pyramids function
    // initilize row_num
    // loop through height
        // call print_empty
        // call print_bricks for left pyramid
        // print space betweent the pyramids
        // call print_bricks for right pyramid
        // print new line


// define print_empty function
    // initilize space_size with (height - row_num)
    // loop throught space_size
        // print space


// define print_bricks function
    // loop through row_num
        // print brick