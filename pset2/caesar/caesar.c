#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    /*Declare some variables*/
    int n, j;

    /*Make sure the array that main recieves has only 2 strings*/
    if (argc == 2)
    {
        /*Get user input for text to be converted*/
        string plaintext = get_string("plaintext: ");

        /*Convert the second string in the array argv into an integer*/
        int k = atoi(argv[1]);

        printf("ciphertext: ");

        /*Use a for loop to pass through each letter of the input*/
        for (n = 0, j = strlen(plaintext); n < j; n++)
        {
            /*Check if the n'th entry is in the alphabet*/
            if (isalpha(plaintext[n]))
            {
                /*Check if the n'th entry is uppper case*/
                if (isupper(plaintext[n]))
                {
                    /*Algorithm to encrypt our input (Captital letter)*/
                    printf("%c", 65 + ((plaintext[n] - 65) + k) % 26);
                }
                /*Encrypt our input if the n'th entry is lower case*/
                else
                {
                    /*Algorithm to encrypt our input (Captital letter)*/
                    printf("%c", 97 + ((plaintext[n] - 97) + k) % 26);
                }
            }
            /*Prints the n'th entry w/o doing anything since it is not a letter in the alphabet*/
            else
            {
                printf("%c", plaintext[n]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Incorrect amount of arguments - should be one.\n");
        return 1;
    }
}