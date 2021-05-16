/**
 * @file singlyCircular.c
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-05-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

#include "singlyCircular.h"

/**     -- Function header comment
 *  FUNCTION        :   append
 *  DESCRIPTION     :   This function is responsible for inserting at the end
 *                      except for the first node.
 *  PARAMETERS      :   head, number
 *  RETRUNS         :   head
 */
struct Node* append(struct Node* head, int number)
{
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->data = number;
    if (head == NULL)
    {   
        head = newNode;
        newNode->next = head;
        return head;
    }
    else if (head->next != NULL)
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        newNode->next = head;
        head->next = newNode;
    }
    return head;
}

/**     -- Function header comment
 *  FUNCTION        :   update
 *  DESCRIPTION     :   This function is responsible for updating a specific
 *                      node of choice.
 *  PARAMETERS      :   head, oldData, newData
 *  RETURNS         :   temp
 */
struct Node* update(struct Node* head, int oldData, int newData)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node* temp = NULL;
    temp = head;
    do
    {   
        if (temp->data == oldData)
        {
            temp->data = newData;
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return temp;
}

/**     -- Function header comment
 *  FUNCTION        :   delete
 *  DESCRIPTION     :   This function is responsible for deleting
 *                      a specific number in the circular list of numbers.
 *  PARAMETERS      :   head, numberToDelete
 *  RETURNS         :   temp
 */
struct Node* delete(struct Node* head, int numberToDelete)
{   
    if (head == NULL)
    {
        return NULL;
    }

    struct Node* temp = NULL;
    temp = head;
    
    while (temp != NULL)
    {   
        if (temp->data == numberToDelete)
        {
            temp->data = 0;
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

/**     -- Function header comment
 *  FUNCTION        :   show
 *  DESCRIPTION     :   This method is responsible for displaying the
 *                      numbers collected.
 *  PARAMETERS      :   head
 *  RETRUNS         :   None
 */
void show(struct Node* head)
{   
    if (head == NULL)
    {
        return;
    }

    struct Node* temp = NULL;
    temp = head;
    do
    {   
        if (temp->data != 0)
        {
            printf("%i ", temp->data);
        }
        
        temp = temp->next;
    } while (temp != head);
}
