/**
 * @file list.c
 * @author Braiden Gole
 * @brief This is a linked list in the C programming language.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

// Header files.
#include "linkedList.h"

int main(void)
{   
    struct Node* head = NULL;
    
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    updateNode(&head, 1, 300);

    deleteNode(&head, 5);
    
    show(head);
    
    freeResources(head);
    return 0;
}