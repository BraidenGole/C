/**
 * @file closedHash.h
 * @author Braiden Gole
 * @brief This is an closed address hash table implementation.
 * @version 0.1
 * @date 2021-05-30
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef CLOSEDHASH
#define CLOSEDHASH "closedHash.h"

#define LIMIT 16

#define __LSS__ <
#define __NEQ__ !=
#define __EQ__ ==

struct HashNode
{
    char* key;
    int value;
};

// Function prototypes.
void prepareBuckets(struct HashNode* table[]);
void insert(struct HashNode* table[], char* key);
struct HashNode* search(struct HashNode* table[], char* key);
void removeHashNode(struct HashNode* table[], char* keyToRemove);
void display(struct HashNode* table[]);
#endif