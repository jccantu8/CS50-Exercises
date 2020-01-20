#include <stdio.h>
#include <cs50.h>
#include <math.h>


long long power(long n);

int main(void)
{

    long long x;
    long long y = 0;
    long long n;

    long long v = 0;
    long long w = 0;

    do
    {
        x = get_long_long("Number: ");
    }
    while (x <= 0);

    for (n = 0; n < 9; n++)
    {

        if((2 * ((x / (10 * power(n))) % 10)) >= 10)
        {
            v += ((2 * ((x / (10 * power(n))) % 10)) / 10) + ((2 * ((x / (10 * power(n))) % 10)) % 10);
        }
        else
        {
            v += 2 * ((x / (10 * power(n))) % 10);
        }
    }

    for (n = 0; n < 9; n++)
    {

        w += ((x / (power(n))) % 10);

    }

    if (((w + v) % 10) == 0)
    {
        if((floor(log10(x)) + 1) == 15 && ((x / 10000000000000) == 37 || (x / 10000000000000) == 34))
        {
            printf("AMEX\n");
        }
        else if((floor(log10(x)) + 1) == 16 && ((x / 100000000000000) == 51 || (x / 100000000000000) == 52 || (x / 100000000000000) == 53 || (x / 100000000000000) == 54 || (x / 100000000000000) == 55))
        {
            printf("MASTERCARD\n");
        }
        else if((floor(log10(x)) + 1) == 13 && (x / 1000000000000) == 4)
        {
            printf("VISA\n");
        }
        else if((floor(log10(x)) + 1) == 16 && (x / 1000000000000000) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

long long power(long n)
{
    long long value = 1;

    if (n == 0)
    {
        return 1;
    }
    else
    {

        while (n > 0)
        {
            value *= (10 * 10);
            n--;
        }

        return value;
    }
}