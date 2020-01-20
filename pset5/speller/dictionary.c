// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

//Define node data type which includes a string and a pointer another node
typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    }
    node;

//Declare an array of pointers to 26 nodes - one for each letter of the alphabet
node *hashtable[26];

//Initialize a counter for the number of words in our dictionary
int counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Variable initialized using our hash function to be used as an index to determine which linked list to insert to in our hashtable
    int key = hash(word);

    //Initialize a node to point to the head of a linked list determined by key
    node *cursor = hashtable[key];

    if (cursor == NULL)
    {
            unload();
            return false;
    }

    //Loop through linked list until reaching the last node
    while (cursor != NULL)
    {
        //Exit loop if word from text passed to program is found in the dictionary (i.e. spelled correctly)
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    //Return false to indicate word was not found in the dictionary (i.e. not spelled correctly)
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");

    //Declare an array 46 characters long to fit any word in the dictionary
    char word[LENGTH+1];

    //Loop through passed text file until reaching the end of the file while examining one word at a time
    while (fscanf(file,"%s", word) != EOF)
    {
        //Initialize a pointer to a node that will be used to used to insert a node into the linked list
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            //Copy word from text into new_node
            strcpy(new_node->word, word);
            //Determine which linked list to insert into
            int hashkey = hash(new_node->word);
            //Insert node into the linked list
            new_node->next = hashtable[hashkey];
            //Change the head of the linked list
            hashtable[hashkey] = new_node;
            //Increment dictionary word counter
            counter++;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //Counter will only be > 0 if dictionary was successfully opened and contained at least 1 word
    if (counter > 0)
    {
        return counter;
    }
    //Returning 0 would be dictionary wasnt opened correctly or doesn't contain any words
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Loop through all 26 linked lists
    for (int i = 0; i <= 25; i++)
    {
        node *cursor = hashtable[i];

        //Free pointers in nodes starting from the head of the linked list. A temporary pointer, cursor, is used to point to the
        //  next node in the linked list in order to continue traversing the linked list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

//Hash function dependent of the first letter of a word. The value returned is place value of that first letter in the alphabet
int hash(const char *a)
{
    int hashkey = toupper(a[0]) - 65;
    return hashkey;
}