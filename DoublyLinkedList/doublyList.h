/**
 * @file doublyList.h
 * @author Braiden Gole
 * @brief This is a doubly linked list implementation.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _DOUBLYLINKEDLIST
#define _DOUBLYLINKEDLIST "doublyList.h"

struct Node
{
    char* data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes.
void insert(struct Node** head, struct Node** tail, char* value);
void deleteNode(struct Node** head, struct Node** tail, char* deleteValue);
void show(struct Node* head);
void showInReverse(struct Node* tail);
void freeResources(struct Node* head);
#endif