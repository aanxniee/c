// import libraries
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define variables and set them as an integer
    int height, row, col1, col2, width;

    // this do-while loop ensures that the user enters a positive height
    do
    {
        // ask the user to enter the height of marios pyramid
        height = get_int("Height: ");
        // set the width
        width = height - 1;
    }
    while (height < 1 || height > 8);

    // this loop prints each row until the desired height is reached
    for (row = 1; row <= height; row++)
    {
        // this loop prints the blank space with one less in each row
        for (col1 = 1; col1 <= width; col1++)
        {
            printf(" ");
        }
        // decrease the width to print one less blank space
        width--;

        // this loop prints the # with one more in each row
        for (col2 = 1; col2 <= row; col2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
