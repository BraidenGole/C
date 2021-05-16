/**
 * @file singlyCircular.h
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-05-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef KSINGLYCIRCULAR
#define KSINGLYCIRCULAR "singlyCircular.h"

struct Node
{
    int data;
    struct Node* next;
};

// Function prototypes.
struct Node* append(struct Node* head, int number);
struct Node* update(struct Node* head, int oldData, int newData);
struct Node* delete(struct Node* head, int numberToDelete);
void show(struct Node* head);
#endif