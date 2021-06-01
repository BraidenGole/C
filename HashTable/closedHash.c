/**
 * @file closedHash.c
 * @author Braiden Gole
 * @brief This is an closed address hash table implementation.
 * @version 0.1
 * @date 2021-05-30
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "closedHash.h"

// Function prototypes.
unsigned int generateHashValue(char* key);
struct HashNode* search(struct HashNode* table[], char* key);

/**     -- Function header comment
 *  FUNCTION        :   prepareBuckets
 *  DESCRIPTION     :   This function is responsible for preparing the buckets
 *                      filling all positions with an empty marker indicating that the
 *                      bucket has not yet been filled.
 *  PARAMETERS      :   table
 *  RETURNS         :   None
 */
void prepareBuckets(struct HashNode* table[])
{
    int buckets = 0;
    while (buckets __LSS__ LIMIT)
    {
        table[buckets] = NULL;
        ++buckets;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   insert
 *  DESCRIPTION     :   This function is responsible for the insertion of the hash node
 *                      where they key gets hashed and out comes a hash value(the position at which
 *                      the hash node will sit in the hash table.)
 *  PARAMETERS      :   table, key
 *  RETURNS         :   None
 */
void insert(struct HashNode* table[], char* key)
{   
    unsigned int hashValue = generateHashValue(key);
    
    struct HashNode* newHashNode = NULL;
    newHashNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (newHashNode __EQ__ NULL)
    {
        return;
    }

    newHashNode->key = key;
    newHashNode->value = hashValue;

    if (table[hashValue] __EQ__ NULL)
    {
        table[hashValue] = newHashNode;
    }
    else
    {   
        int bucketsVisited = 0;
        while (table[hashValue] __NEQ__ NULL)
        {   
            // Keep searching for a spot in all potential spots.
            if (bucketsVisited __EQ__ LIMIT - 1)
            {
                return;
            }
            ++bucketsVisited;
            ++hashValue;

            // Wrap around.
            hashValue %= LIMIT;
        }
        newHashNode->value = hashValue;
        table[hashValue] = newHashNode;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   search
 *  DESCRIPTION     :   This function is responsible for searching the hash table
 *                      by hashing the key to efficiently search for the node.
 *  PARAMETERS      :   table, key
 *  RETURNS         :   table[hashValue]
 */
struct HashNode* search(struct HashNode* table[], char* key)
{
    unsigned int hashValue = generateHashValue(key);
    while (table[hashValue] __NEQ__ NULL)
    {
        if (table[hashValue]->key __EQ__ key)
        {
            return table[hashValue];
        }
        ++hashValue;

        // Wrap around.
        hashValue %= LIMIT;
    }
    return NULL;
}

/**     -- Function header comment
 *  FUNCTION        :   remove
 *  DESCRIPTION     :   This function is responsible for removing a hash node from the
 *                      hash table.
 *  PARAMETERS      :   table, keyToRemove
 *  RETURNS         :   None
 */
void removeHashNode(struct HashNode* table[], char* keyToRemove)
{
    unsigned int hashValue = generateHashValue(keyToRemove);
    while (table[hashValue] __NEQ__ NULL)
    {
        if (table[hashValue]->key __EQ__ keyToRemove)
        {
            struct HashNode* delete = NULL;
            delete = table[hashValue];
            table[hashValue] = NULL;
            break;
        }
        ++hashValue;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   display
 *  DESCRIPTION     :   This function will display the hash table keys and values.
 *  PARAMETERS      :   table
 *  RETURNS         :   None
 */
void display(struct HashNode* table[])
{   
    printf(" -- Hash table -- \n");
    for (int buckets = 0; buckets __LSS__ LIMIT; buckets++)
    {
        if (table[buckets] __NEQ__ NULL)
        {
            printf("\t%s - %i\n", table[buckets]->key, table[buckets]->value);
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   generateHashValue
 *  DESCRIPTION     :   This function is responsible for generating the hash value, 
 *                      the position at which the hash node will sit in the hash table.
 *  PARAMETERS      :   key, 
 *  RETURNS         :   hashValue
 */
unsigned int generateHashValue(char* key)
{
    unsigned long hashValue = 0;
    for (int letters = 0; letters __LSS__ strlen(key); letters++)
    {
        hashValue += key[letters];
        hashValue *= key[letters];
    }
    return hashValue % LIMIT;
}