#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // get user input only if it is valid.
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int num = 1;
    // how many blocks (hashes) on each side.
    int num_of_blocks = 1;

    // for every row.
    for (int i = 0; i < n; i++)
    {
        //print the requird number of spaces.
        for (int j = num ; j < n; j++)
        {
            printf(" ");
        }
        num++;
        //print the requird number of blocks.
        for (int k = 0; k < num_of_blocks; k++)
        {
            printf("#");
        }
        // print the gap.
        printf("  ");
        //print the requird number of blocks for the right side.
        for (int k = 0; k < num_of_blocks; k++)
        {
            printf("#");
        }
        num_of_blocks++;
        printf("\n");
    }
}