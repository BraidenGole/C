/**
 * @file open.c
 * @author Braiden Gole
 * @brief This is a open address hash table.
 * @version 0.1
 * @date 2021-06-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <string.h>

// Header files.
#include "openHash.h"

int main(void)
{
    struct HashNode* hashTable[LIMIT];

    // Prepare the reference table to get the bucket.
    markBuckets(hashTable);

    char buffer[K100BYTES] = {""};

    addNode(hashTable, "Jaden");
    addNode(hashTable, "Kaden");
    addNode(hashTable, "Sarah");
    addNode(hashTable, "Terah");
    addNode(hashTable, "Braiden");
    addNode(hashTable, "Brandon");
    addNode(hashTable, "Braydon");
    addNode(hashTable, "Brant");
    addNode(hashTable, "Brent");

    struct HashNode* find = NULL;
    find = search(hashTable, "Braiden");
    if (find __NEQ__ NULL)
    {
        printf("%s has been found at %i\n", find->key, find->value);
    }

    find = search(hashTable, "Brant");
    if (find __NEQ__ NULL)
    {
        printf("%s has been found at %i\n", find->key, find->value);
    }

    find = search(hashTable, "Brent");
    if (find __NEQ__ NULL)
    {
        printf("%s has been found at %i\n", find->key, find->value);
    }

    // Uncomment the lines below.
    // removeNode(hashTable, "Braiden");
    // removeNode(hashTable, "Brandon");
    // removeNode(hashTable, "Braydon");

    // removeNode(hashTable, "Brant");
    // removeNode(hashTable, "Brent");
    // removeNode(hashTable, "Kaden");
    // removeNode(hashTable, "Jaden");
    display(hashTable);
    return 0;
}