#include <stdio.h>
#include <cs50.h>

int main(void)
{

    /* Initialize variable */
    int x, i, n, j;

    /* Prompt user input for an integer between 0 and 23 inclusive */
    do
    {
        x = get_int("How many blocks do you want? ");
    }
    while (x < 0 || x > 23);


    /* Create a for loop to control the height of the pyramid */
    for (j = 0; j < x; j++)
    {

        /* Create a for loop to control the number of spaces */
        for (i = 0; (x - (i + 1)) > j; i++)
        {
            printf(" ");

        }

        /* Create a for loop to control the number of hashes */
        for (n = 0; (j + 2) > n ; n++)
        {
            printf("#");

        }

        /* Print a new line for each row of the pyramid */
        printf("\n");

    }
}


