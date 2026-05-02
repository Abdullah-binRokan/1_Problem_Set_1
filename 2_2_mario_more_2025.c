// print mario adjacent pyramids
#include <cs50.h>
#include <stdio.h>

// declare functions prototypes
void create_pyramids(int height);
void print_empty(int height, int row_num);
void print_bricks(int row_num);

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
    create_pyramids(height);
}


// define create_pyramids function
void create_pyramids(int height)
{
    int row_num = 1;
    for (int i = 0; i < height; i++)
    {
        // print space for the row of the left pyramid
        print_empty(height, row_num);
        // call print_bricks for left pyramid
        print_bricks(row_num);
        // print space betweent the pyramids
        printf("  ");
        // call print_bricks for right pyramid
        // print new line and increment row_num
        printf("\n");
        row_num++;
    }
}

// define print_empty function
void print_empty(int height, int row_num)
{
    // initilize space_size with (height - row_num)
    int space_size = height - row_num;
    for (int space = 0; space < space_size; space++)
    {
        printf(" ");
    }
}
    

// define print_bricks function
void print_bricks(int row_num)
{
    for (int brick = 0; brick < row_num; brick++)
    {
        printf("#");
    }
} 