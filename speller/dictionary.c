// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// t0 determine the size of dictionary
int tally = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//declartion of recursive function clean
void clean(node *p);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //declartion
    node *trav = NULL;
    int index = 0;
    //take index from hash function
    index = hash(word);

    if (table[index] == NULL)
    {
        return false;
    }
    else
    {
        trav = table[index];
        //traverse the linked list
        while (trav != NULL)
        {
            //check for word
            if ((strcasecmp(word, (trav -> word))) == 0)
            {
                return true;
            }
            trav = trav -> next;
        }
    }
    //if not found return false
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A') % 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int index;
    node *n;
    char buffer[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", buffer) != EOF)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, buffer);
        index = hash(n -> word);

        n -> next = table[index];
        table[index] = n;
        tally++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (tally == 0)
    {
        return 0;
    }
    else
    {
        return tally;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        clean(table[i]);
    }
    return true;
}

// recursive function to free
void clean(node *p)
{
    if (p == NULL)
    {
        return;
    }
    clean(p -> next);
    free(p);
}