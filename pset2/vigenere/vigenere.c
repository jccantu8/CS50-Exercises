#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    /*Make sure the array that main recieves has only 2 strings*/
    if (argc != 2)
    {
        printf("Incorrect amount of arguments - should be one.\n");
        return 1;

    }
    else
    {

        /*Declare some variables*/
        int n, j, p, v, m, y;
        /*Declare an array of integers that will hold the alphabetical indices of our keyword*/
        int keywordarray[strlen(argv[1])];


        /*Make sure the keyword is only alphabetical*/
        for (v = 0; v < strlen(argv[1]); v++)
        {
            if (isalpha((argv[1])[v]))
            {
                ;
            }
            else
            {
                printf("Your keyword should only contain letters.\n");
                exit(1);
            }
        }

        /*Get the plaintext from the user*/
        string plaintext = get_string("plaintext: ");

        /*Convert each character of our keyword into its corresponding alphabetical index and assign it to our array*/
        for (m = 0; m < strlen(argv[1]); m++)
        {
            if (isupper(argv[1][m]))
            {
                keywordarray[m] = argv[1][m] - 65;
            }
            else
            {
                keywordarray[m] = argv[1][m] - 97;
            }
        }

        printf("ciphertext: ");

        /*Use a for loop to pass through each letter of the input / Use y to handle moving along our keyword only when we have an alphabetical value*/
        for (n = 0, j = strlen(plaintext), y = 0; n < j; n++)
        {
            /*Check if the n'th entry is in the alphabet*/
            if (isalpha(plaintext[n]))
            {
                /*Check if the n'th entry is upper case*/
                if (isupper(plaintext[n]))
                {
                    /*Algorithm to encrypt our input (Captital letter)*/
                    printf("%c", 65 + ((plaintext[n] - 65) + keywordarray[y % strlen(argv[1])]) % 26);
                    y++;
                }
                /*Encrypt our input if the n'th entry is lower case*/
                else
                {
                    /*Algorithm to encrypt our input*/
                    printf("%c", 97 + ((plaintext[n] - 97) + keywordarray[y % strlen(argv[1])]) % 26);
                    y++;
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
}