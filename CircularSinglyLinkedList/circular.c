/**
 * @file circular.c
 * @author Braiden Gole
 * @brief This is a Circular Singly linked list.
 * @version 0.1
 * @date 2021-05-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#include "singlyCircular.h"

int main(void)
{
    struct Node* head = NULL;

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    head = append(head, 6);
    head = append(head, 7);
    
    head = update(head, 7, 30);

    head = delete(head, 30);

    show(head);
    return 0;
}
