// Implements a dictionary's functionality
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N] = {NULL};
unsigned int count;

// Hashes word to a number, algorithm "djb2" source: http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash = 5381;
    int c = 0;

    while (c == *word++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % N;

}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char lowercase[LENGTH+1];

    for(int i = 0; i < len+1; i++){
        lowercase[i] = tolower(word[i]);
    }

    node *trav = table[hash(lowercase)];

    while(trav != NULL){
        if (strcasecmp(trav->word, word) == 0)
            return true;
        else
            trav = trav->next;
    }

    return false;
}

struct node *createNode(const char* words){
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL){
        printf("No available memory to allocate. Exiting\n");
        unload();
        return false;
    }
    newNode->next = NULL;
    strcpy(newNode->word, words);

    return newNode;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    char words[LENGTH+2];
    unsigned int hashed = 0;

    FILE *file = fopen(dictionary, "r");
    if (!file){
        printf("File could not be opened. Operation Terminated.\n");
        return false;
    }

    while (fscanf(file, "%s", words) != EOF){
        hashed = hash(words);

        if (table[hashed] == NULL){
            table[hashed] = createNode(words);
            count++;
        }
        else{
            node *newNode = createNode(words);
            newNode->next = table[hashed];
            table[hashed] = newNode;
            count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int *numWords = &count;
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++){
        node *trav = table[i];
        while(trav != NULL){
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }
    return true;
}
