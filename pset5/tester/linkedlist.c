#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cs50.h>

#define LENGTH 45

#define DICTIONARY "dictionaries/large"

int hash(char *a);

int main(int argc, char *argv[])
{

if (argc != 2 && argc != 3)
    {
        printf("Usage: speller [dictionary] text\n");
        return 1;
    }

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;

char *text = (argc == 3) ? argv[2] : argv[1];
FILE *file = fopen(text, "r");

node *hashtable[26];


char word[LENGTH+1];

while (fscanf(file,"%s", word) != EOF)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    else
    {
        strcpy(new_node->word, word);
        int hashkey = hash(new_node->word);
        new_node->next = hashtable[hashkey];
        hashtable[hashkey] = new_node;
    }
}

node *test = hashtable[1];

while (strcmp(test->word, "boy") != 0)
{
    printf("%s\n", test->word);
    test = test->next;

}

}

int hash(char *a)
{
    int hashkey = toupper(a[0]) - 65;
    return hashkey;
}