/**
 * @file linkedList.c
 * @author Braiden Gole
 * @brief This is a linked list in the C programming language.
 * @version 0.1
 * @date 2021-06-29
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header files.
#include "linkedList.h"

// Function prototypes.
bool checkForDuplicates(struct Node** head, int valueToCheck);

/**     -- Function header comments
 *  FUNCTION        :   insert
 *  DESCRIPTION     :   This function will insert a new node into our linked list.
 *  PARAMETERS      :   head, value
 *  RETURNS         :   None
 */
void insert(struct Node** head, int value)
{
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return;
    }

    bool duplicates = false;
    duplicates = checkForDuplicates(head, value);
    if (duplicates == true)
    {
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        *head = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

/**     -- Function header comment
 *  FUNCTION        :   checkForDuplicates
 *  DESCRIPTION     :   This function will check the linked list for any duplicate numbers.
 *  PARAMETERS      :   head, valueToCheck
 *  RETURNS         :   true, false
 */
bool checkForDuplicates(struct Node** head, int valueToCheck)
{
    struct Node* headReference = NULL;
    headReference = *head;

    while (headReference != NULL)
    {
        if (headReference->data == valueToCheck)
        {
            return true;
        }
        headReference = headReference->next;
    }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   updateNode
 *  DESCRIPTION     :   This will update a node in the linked list.
 *  PARAMETERS      :   head, value, updateValue
 *  RETUNRS         :   None
 */
void updateNode(struct Node** head, int value, int updateValue)
{
    struct Node* headReference = NULL;
    headReference = *head;

    while (headReference != NULL)
    {   
        if (headReference->data == value)
        {
            headReference->data = updateValue;
        }
        headReference = headReference->next;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   deleteNode
 *  DESCRIPTION     :   This will delete a node at the head.
 *  PARAMETERS      :   head
 *  RETURNS         :   None
 */
void deleteNode(struct Node** head, int deleteValue)
{
    struct Node* headReference = NULL;
    struct Node* previous = NULL;

    headReference = *head;
    if (headReference != NULL)
    {   
        if (headReference->data == deleteValue)
        {
            *head = headReference->next;
            free(headReference);
            return;
        }
    }

    while (headReference != NULL)
    {
        if (headReference->data == deleteValue)
        {
            break;
        }
        previous = headReference;
        headReference = headReference->next;
    }

    if (headReference == NULL)
    {
        return;
    }
    previous->next = headReference->next;
    free(headReference);
}   

/**     -- Function header comment
 *  FUNCTION        :   show
 *  DESCRIPTION     :   This function will show the linked list.
 *  PARAMETERS      :   head
 *  RETURNS         :   None
 */
void show(struct Node* head)
{   
    printf("\n");
    struct Node* headReference = NULL;
    headReference = head;
    while (headReference != NULL)
    {
        printf("%i ", headReference->data);
        headReference = headReference->next;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   freeResources
 *  DESCRIPTION     :   This will free all dynamically allocated memory.
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