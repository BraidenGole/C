/**
 * @file doublyList.c
 * @author Braiden Gole
 * @brief This is a doubly linked list implementation.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header files.
#include "doublyList.h"

/**     -- Function header comment
 *  FUNCTION        :   insert
 *  DESCRIPTION     :   This function will insert a new node into our doubly linked list.
 *  PARAMETERS      :   head, tail, value
 *  RETURNS         :   None
 */
void insert(struct Node** head, struct Node** tail, char* value)
{
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        struct Node* lastNode = NULL;
        struct Node* nextNode = NULL;
        
        lastNode = *head;
        nextNode = (*head)->next;

        while (nextNode != NULL)
        {
            lastNode = nextNode;
            nextNode = nextNode->next;
        }
        newNode->prev = lastNode;
        newNode->next = nextNode;
        lastNode->next = newNode;

        if (nextNode == NULL)
        {
            *tail = newNode;
        }
        else
        {
            nextNode->prev = newNode;
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   deleteNode
 *  DESCRIPTION     :   This function will delete a single node in the doubly linked list.
 *  PARAMETERS      :   head, tail, deleteValue
 *  RETURNS         :   None
 */
void deleteNode(struct Node** head, struct Node** tail, char* deleteValue)
{
    struct Node* thisNode = NULL;

    thisNode = *head;
    while (thisNode != NULL)
    {
        if ((strcmp(thisNode->data, deleteValue)) == 0)
        {   
            if (thisNode == *head)
            {
                *head = thisNode->next;
            }
            if (thisNode->next != NULL)
            {
                thisNode->next->prev = thisNode->prev;
            }
            if (thisNode->prev != NULL)
            {
                thisNode->prev->next = thisNode->next;
            }
            free(thisNode);
        }
        thisNode = thisNode->next;
    }
}   

/**     -- Function header comment
 *  FUNCTION        :   show
 *  DESCRIPTION     :   This function will show every node in the doubly linked list.
 *  PARAMETERS      :   head
 *  RETURNS         :   None
 */
void show(struct Node* head)
{
    struct Node* headReference = NULL;

    headReference = head;
    while (headReference != NULL)
    {
        printf("%s\n", headReference->data);
        headReference = headReference->next;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   showInReverse
 *  DESCRIPTION     :   This will show every node in the doubly linked list in reverse.
 *  PARAMETERS      :   tail
 *  RETURNS         :   None
 */
void showInReverse(struct Node* tail)
{
    struct Node* tailReference = NULL;

    tailReference = tail;
    while (tailReference != NULL)
    {   
        printf("%s\n", tailReference->data);
        tailReference = tailReference->prev;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   freeResources
 *  DESCRIPTION     :   This function will free the program of all dynamic allocations.
 *  PARAMETERS      :   head
 *  RETURNS         :   None
 */
void freeResources(struct Node* head)
{
    struct Node* headReference = NULL;
    struct Node* currentNode = NULL;

    headReference = head;
    while (headReference != NULL)
    {
        currentNode = headReference;
        headReference = headReference->next;
        free(currentNode);
    }
}
