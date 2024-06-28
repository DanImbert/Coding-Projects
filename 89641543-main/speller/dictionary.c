// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int countWord = 0;

// Hash table
node *table[N];
unsigned int hash(const char *word);
void freenode(node *n);


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int hashNum = hash(word);
    node *cursor = table[hashNum];
    while(cursor != NULL)
    {
        //check if words are the same
        if(strcasecmp(cursor ->word, word) == 0)
        {
            return true;
        }
        //else, move cursor to the next node
       cursor = cursor ->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open Dictionary

    FILE *DictFile = fopen(dictionary, "r");

    //Check if value is null
    if(DictFile == NULL)
    {
        return false;
    }

    //read strings one file at a time
    char str[LENGTH + 1];
    while(fscanf(DictFile, "%s", str) != EOF)
    {
        //create a node for each new word
        node *temp = malloc(sizeof(node));
        //check if return value in NULL
        if(temp == NULL)
        {
            return false;
        }

        //copy word into node using strcopy
        strcpy(temp -> word, str);

        //Use hash function
        int hashNum = hash(str);

        //Check if the HEAD is pointing to NULL
        if(table[hashNum] == NULL)
        {
            //Point temp to NULL
            temp ->next = NULL;
        }

         else
        {

         // point temp to first node of the linked list

         temp->next = table[hashNum];
        }

        // Point the header to temp
        table [hashNum] = temp;
        countWord += 1;

    }
    //Close the file
    fclose(DictFile);
    return true;

}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return countWord;
}

void freenode(node *n)
{
    if(n -> next != NULL)
    {
        freenode (n ->next);
    }
    free(n);
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
