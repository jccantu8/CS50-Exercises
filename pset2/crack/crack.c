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
/*################################################################################################################################*/
        for (int i1 = 0; i1 < 26; i1++)
        {
            char guess[2];

            guess[0] = 'A' + i1;
            if (strcmp(crypt(guess, "50"), argv[1]) == 0)
            {
                printf("%s\n", guess);
                exit(1);
            }

            guess[0] = 'a' + i1;
            if (strcmp(crypt(guess, "50"), argv[1]) == 0)
            {
                printf("%s\n", guess);
                exit(1);
            }

        }
/*################################################################################################################################*/

        for (int i1 = 0; i1 < 26; i1++)
        {
            char guess[3];

            guess[0] = 'A' + i1;

            for (int i3 = 0; i3 < 26; i3++)
            {
                guess[1] = 'A' + i3;
                if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                {
                    printf("%s\n", guess);
                    exit(1);
                }

                guess[1] = 'a' + i3;
                if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                {
                    printf("%s\n", guess);
                    exit(1);
                }
            }

            guess[0] = 'a' + i1;

            for (int i3 = 0; i3 < 26; i3++)
            {
                guess[1] = 'A' + i3;
                if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                {
                    printf("%s\n", guess);
                    exit(1);
                }

                guess[1] = 'a' + i3;
                if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                {
                    printf("%s\n", guess);
                    exit(1);
                }
            }

        }

/*################################################################################################################################*/

        for (int i1 = 0; i1 < 26; i1++)
        {
            char guess[4];
            guess[0] = 'A' + i1;

            for (int i2 = 0; i2 < 26; i2++)
            {
                guess[1] = 'A' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }

                    guess[2] = 'a' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }
                }

                guess[1] = 'a' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }

                    guess[2] = 'a' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }
                }

            }

            guess[0] = 'a' + i1;

            for (int i2 = 0; i2 < 26; i2++)
            {
                guess[1] = 'A' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }

                    guess[2] = 'a' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }
                }


                guess[1] = 'a' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }

                    guess[2] = 'a' + i3;
                    if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                    {
                        printf("%s\n", guess);
                        exit(1);
                    }
                }

            }

        }

/*################################################################################################################################*/

        for (int i1 = 0; i1 < 26; i1++)
        {
            char guess[5];
            guess[0] = 'A' + i1;

            for (int i2 = 0; i2 < 26; i2++)
            {
                guess[1] = 'A' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;

                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }


                    guess[2] = 'a' + i3;

                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }
                }

                guess[1] = 'a' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;

                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }

                    guess[2] = 'a' + i3;

                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }
                }

            }

            guess[0] = 'a' + i1;

            for (int i2 = 0; i2 < 26; i2++)
            {
                guess[1] = 'A' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }

                    guess[2] = 'a' + i3;
                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }
                }


                guess[1] = 'a' + i2;

                for(int i3 = 0; i3 < 26; i3++)
                {
                    guess[2] = 'A' + i3;
                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }

                    guess[2] = 'a' + i3;
                    for (int i4 = 0; i4 < 26; i4++)
                    {
                        guess[3] = 'A' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }

                        guess[3] =  'a' + i4;
                        if (strcmp(crypt(guess, "50"), argv[1]) == 0)
                        {
                            printf("%s\n", guess);
                            exit(1);
                        }
                    }
                }

            }

        }

/*################################################################################################################################*/

    }

}