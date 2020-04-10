// Implements a dictionary's functionality
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Mention the hash function as a prototype
unsigned int hash(const char *word);

const unsigned int N = 2000; // Set number of buckets in the hashtable
int count = 0; // Create a word counter
node *table[N]; // Create a pointer to the hashtable

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int word_length = strlen(word); // Find out the length of each word
    char buffer[word_length + 1];
    // Add a null terminator to the end of each word
    buffer[word_length] = '\0';

    for (int i = 0; i < word_length; i++)
    {
        buffer[i] = tolower(word[i]); // Convert the word to lower case
    }

    // Pass each lower case word through the hash function
    int index = hash(buffer) % N;
    node *head = table[index]; // Set the head for the linked list

    if (head != NULL)
    {
        node *cursor = head; // Set the cursor to the location of the head

        // As long as cursor is not null, compare the words
        while (cursor != NULL)
        {
            // Returns true if the word is found in the dictionary
            if (strcmp(cursor->word, buffer) == 0)
            {
                return true;
            }

            else // If it is not found, it moves the cursor to the next word
            {
                cursor = cursor->next;
            }
        }
    }
    return false;
}

/*
Hash table from https://stackoverflow.com/questions/7666509/hash-function-for-string
*/
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the file for reading
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) // If the file cannot be opened, display error message
    {
        printf("Count not open %s\n", dictionary);
        return false;
    }

    char temp[LENGTH + 1]; // Create a buffer to store the words
    int n = LENGTH + 2;

    // Scan through the file and load each word into the hashtable
    while (fgets(temp, n, file) != NULL)
    {
        temp[strlen(temp) - 1] = '\0';
        int h = hash(temp) % N; // Find the index of the array that the word should be stored at

        // Allocate memory for each new word
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL) // If memory could not be allocated, display error message
        {
            fclose(file);
            return false;
        }

        // Put the word into the new node
        strcpy(new_word->word, temp);
        new_word->next = table[h];
        table[h] = new_word;
        count++; // Increment the word count
    }

    fclose(file); // Close the file
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
    for (int i = 0; i < N; i++) // Iterate through the buckets
    {
        // Point the cursor to every index
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // If the cursor is not null, point a temp to point the same node
            node *tmp = cursor;
            cursor = cursor->next; // Move the cursor to the next node

            free(tmp); // Free the current node
        }
    }
    return true;
}
