/**
 * @file linkedList.h
 * @author Braiden Gole
 * @brief This is a linked list implementation.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _LINKEDLIST
#define _LINKEDLIST "linkedList.h"

struct Node
{
    int data;
    struct Node* next;
};

// Function prototypes.
void insert(struct Node** head, int value);
void updateNode(struct Node** head, int value, int updateValue);
void deleteNode(struct Node** head, int deleteValue);
void show(struct Node* head);
void freeResources(struct Node* head);
#endif