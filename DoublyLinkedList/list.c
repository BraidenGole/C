/**
 * @file list.c
 * @author Braiden Gole
 * @brief This is a doubly liked list implementation.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "doublyList.h"

int main(void)
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    insert(&head, &tail, "Brant");
    insert(&head, &tail, "Zeta");
    insert(&head, &tail, "Braiden");
    insert(&head, &tail, "Alpha");
  
    //deleteNode(&head, &tail, "Alpha");

    show(head);

    //showInReverse(tail);

    freeResources(head);
    return 0;
}