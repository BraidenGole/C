/**
 * @file openHash.h
 * @author Braiden Gole
 * @brief This is a open address hash table.
 * @version 0.1
 * @date 2021-06-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef OPENHASH
#define OPENHASH "openHash.h"

#define __NEQ__ !=
#define __EQ__ ==
#define __LSS__ <
#define AND &&
#define LIMIT 33
#define K100BYTES 100

struct HashNode
{
    char* key;
    int value;
    struct HashNode* next;
};

// Function header comment
void markBuckets(struct HashNode* table[]);
void addNode(struct HashNode* table[], char* key);
struct HashNode* search(struct HashNode* table[], char* searchItem);
void removeNode(struct HashNode* table[], char* removeItem);
void display(struct HashNode* table[]);
#endif