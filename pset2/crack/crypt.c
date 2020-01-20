#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Incorrect amount of arguments - should be one.\n");
        return 1;
    }
    else
    {
        if (strcmp(crypt("hi", "50"), argv[1]) == 0)
                {
                    printf("good");
                }
                else
                {
                    printf("%s\n", crypt("abc", "50"));
                }

    }
}



