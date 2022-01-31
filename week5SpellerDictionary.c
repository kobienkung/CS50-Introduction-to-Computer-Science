// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);
    node *cur = table[h];

    while (cur)
    {
        if (strcasecmp(cur->word, word) == 0)
        return true;

        cur = cur->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = *word;
    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
        return false;

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            unload();
            return false;
        }

        strcpy(newNode->word, word);

        int h = hash(word);

        if (table[h])
            newNode->next = table[h];

        table[h] = newNode;
        count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp;
        node *cur = table[i];
        while (cur)
        {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    return true;
}
