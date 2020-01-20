#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    /* Initialize our variables */
    float x;
    int y;
    int z = 0;


    /* Get the user's input */
    do
    {
        x = get_float("Change owed? ");
    }
    while (x < 0);

    /* Convert our change to strictly cents and then assign that to an int y */
    y = round(x * 100);

    /* Use while loops to determine the minimum amount of coins needed */
    while (y >= 25)
    {
        z++;
        y -= 25;
    }

    while (y >= 10)
    {
        z++;
        y -= 10;
    }

    while (y >= 5)
    {
        z++;
        y -= 5;
    }

    while (y >= 1)
    {
        z++;
        y -= 1;
    }

    /* Print our amount of coins needed */
    printf("%i\n", z);

}