#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    bool isWord;
    struct node* children[27];
}
node;

int count = 0;

//root of the trie data structure used in the "load" function
struct node *root = NULL;

// Returns true if word is in dictionary else false.
bool check(const char* word)
{
    int k = strlen(word);
    node *checkSample = root;
    int i;
    for (i = 0; i < k; i++)
    {
        int charValue = 0;

        if (isalpha(word[i]))
        {
            charValue = tolower(word[i]) - 'a';
        }
        else
        {
            charValue = 26;
        }

        if (checkSample->children[charValue] == NULL)
        {
            return false;
        }

        checkSample = checkSample->children[charValue];
    }
    return checkSample->isWord;
}

// Loads dictionary into memory.  Returns true if successful else false.
bool load(const char* dictionary)
{
    // open the dictionary file
    FILE *dict = fopen(dictionary, "r");
    root = calloc(1, sizeof(node));

    // check if the file stream has been opened correctly
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(dict, "%s\n", word) != EOF)
    {
        node *guide = root;
        int len = strlen(word);
        int i;
        for (i = 0; i < len; i++)
        {
            int numValue = 0;
            if (isalpha(word[i]))
            {
                numValue = word[i] - 'a';
            }
            else
            {
                numValue = 26;
            }

            if (guide->children[numValue] == NULL)
            {
                guide->children[numValue] = calloc(1, sizeof(node));
            }
            guide = guide->children[numValue];
        }
        guide->isWord = true;
        count++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded.
unsigned int size(void)
{
    return count;
}

void free_trie(node *rootPtr)
{
    if (rootPtr != NULL)
    {
        int i;
        for (i = 0; i < 27; i++)
        {
            free_trie(rootPtr->children[i]);
        }
    }

    free(rootPtr);
    rootPtr = NULL;
    return;
}

// Unloads dictionary from memory.  Returns true if successful else false.

bool unload(void)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        free_trie(root->children[i]);
    }

    free(root);
    root = NULL;

    if (root == NULL)
    {
        return true;
    }

    return false;
}