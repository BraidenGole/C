/**
 * @file closed.c
 * @author Braiden Gole
 * @brief This is an closed address hash table implementation.
 * @version 0.1
 * @date 2021-05-30
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#include "closedHash.h"

int main(void)
{
    struct HashNode* table[LIMIT];

    // Initialize buckets with a null marker to indicate a empty position.
    prepareBuckets(table);

    insert(table, "Braiden");
    insert(table, "Brant");
    insert(table, "Kim");
    insert(table, "Dave");
    insert(table, "Jason");
    insert(table, "Lori");
    insert(table, "Amy");
    insert(table, "Justin");
    insert(table, "Fran");
    insert(table, "Jen");

    struct HashNode* find = NULL;
    find = search(table, "Brant");
    if (find __NEQ__ NULL)
    {
        printf("\n[%s] was found !\n", find->key);
    }

    find = search(table, "Braiden");
    if (find __NEQ__ NULL)
    {
        printf("[%s] was found !\n", find->key);
    }

    find = search(table, "Kim");
    if (find __NEQ__ NULL)
    {
        printf("[%s] was found !\n", find->key);
    }

    find = search(table, "Dave");
    if (find __NEQ__ NULL)
    {
        printf("[%s] was found !\n\n", find->key);
    }

    removeHashNode(table, "Fran");
    removeHashNode(table, "Jen");
    removeHashNode(table, "Justin");
    removeHashNode(table, "Amy");

    // Show what is inserted inside of the hash table.
    display(table);
    return 0;
}