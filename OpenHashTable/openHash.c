/**
 * @file openHash.c
 * @author Braiden Gole
 * @brief This is a open address hashValue table.
 * @version 0.1
 * @date 2021-06-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header files.
#include "openHash.h"

// Function prototypes.
unsigned long djb2(char* key);

/**     -- Function header comment
 *  FUNCTION        :   markBuckets
 *  DESCRIPTION     :   This function will mark the buckets as empty.
 *  PARAMETERS      :   table
 *  RETURNS         :   None
 */
void markBuckets(struct HashNode* table[])
{
    for (int buckets = 0; buckets __LSS__ LIMIT; buckets++)
    {
        table[buckets] = NULL;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   addNode
 *  DESCRIPTION     :   This method is responsible for inserting into the hash table.
 *  PARAMETERS      :   table, key
 *  RETURNS         :   None
 */
void addNode(struct HashNode* table[], char* key)
{   
    unsigned long hashValue = djb2(key);

    struct HashNode* newHashNode = NULL;
    newHashNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (newHashNode __EQ__ NULL)
    {
        return;
    }

    newHashNode->key = key;
    newHashNode->value = hashValue;
    newHashNode->next = NULL;

    // Get the position
    if (table[hashValue] __EQ__ NULL)
    {
        table[hashValue] = newHashNode;
    }
    else
    {
        struct HashNode* node = NULL;

        node = table[hashValue];
        while (node->next __NEQ__ NULL)
        {
            node = node->next;
        }
        node->next = newHashNode;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   search
 *  DESCRIPTION     :   This will search the hash table for an entry.
 *  PARAMETERS      :   table, searchItem
 *  RETURNS         :   node
 */
struct HashNode* search(struct HashNode* table[], char* searchItem)
{
    struct HashNode* node = NULL;
    unsigned long hashValue = djb2(searchItem);

    node = table[hashValue];
    while (node __NEQ__ NULL)
    {
        if ((strcmp(node->key, searchItem)) __EQ__ 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/**     -- Function header comment
 *  FUNCTION        :   removeNode  
 *  DESCRIPTION     :   This function allows the user to delete a node in the chain.
 *  PARAMETERS      :   table, removeItem
 *  RETURNS         :   None
 */
void removeNode(struct HashNode* table[], char* removeItem)
{   
    struct HashNode* node = NULL;
    unsigned long hashValue = djb2(removeItem);

    node = table[hashValue];

    struct HashNode* delete = NULL;
    while (node __NEQ__ NULL)
    {
        if ((strcmp(node->key, removeItem)) __EQ__ 0)
        {
            delete = node;
            node = node->next;
            free(delete);
            delete->key = "(null)";
            break;
        }
        node = node->next;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   display
 *  DESCRIPTION     :   This method is used to display the chains in the hash table when
 *                      a collision occurs.
 *  PARAMETERS      :   table
 *  RETURNS         :   None
 */
void display(struct HashNode* table[])
{   
    struct HashNode* node = NULL;
    for (int buckets = 0; buckets __LSS__ LIMIT; buckets++)
    {   
        printf("hashTable[%i] --> ", buckets);
        node = table[buckets];
        while (node __NEQ__ NULL)
        {
            printf("%s >>> ", node->key);
            node = node->next;
        }
        printf("NULL\n");
    }
}

/**     -- Function header comment
 *  FUNCTION        :   djb2
 *  DESCRIPTION     :   This method is responsible for generating the hash value.
 *  PARAMETERS      :   key
 *  RETURNS         :   hashValue
 */
unsigned long djb2(char* key)
{   
    unsigned long hashValue = 5381;
    for (int letters = 0; letters __LSS__ strlen(key); letters++)
    {
        hashValue = ((hashValue << 5) + hashValue) + key[letters];
    }
    return hashValue % LIMIT;
}