/**
 * @file pointersExample.c
 * @author Braiden Gole
 * @brief This is a example on pointers, this file will be used as
 *        extra space to write the example functions.
 * ---------------------------------------------------------------
 * This is more of a information sample rather than a sample executable.
 * @version 0.1
 * @date 2021-01-22
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Header file.
#include "pointersExample.h"

/**     -- Function header comment
 *  FUNCTION        :   nEnterDataIntoHead
 *  DESCRIPTION     :   This function will write data into a head variable
 *                      we are pretending that we are constructing part of
 *                      a link-list algorithm where we are writting to a
 *                      newNode and assigning it to the head. In this example
 *                      [IMPORTANT:] We have to either return the pointer if we
 *                                   want access to the written reference or we have to
 *                                   use a "Double pointer !"
 *                      [IMPORTANT:] The advantages with a double pointer is that we
 *                                   can set the return type of the function to whatever
 *                                   we want and still be able to manipulate the variables
 *                                   as well as get the reference.
 *  PARAMETERS      :   head, data
 *  RETURNS         :   head, NULL
 */
struct Node* nEnterDataIntoHead(struct Node* head, const char* data)
{
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    // Is there memory left to allocate.
    if (newNode == NULL)
    {
        return NULL;
    }
    else
    {
        // If there is write the data.

        // [NOTE] In "pointersExample.h" we define the name variable as an
        // array with square brackets which "IS A POINTER" but I will differentiate between
        // the terms "array square brackets" vs "star pointer ! (*)" 

        // When we defined name as 
        // char name[]
        // instead of 
        // char* name
        // then typically we would have to write every character to the array or we could use
        // a built in function to do that. Now if we go the other route we have to dynamically
        // allocate the star pointer then we can assign values to it
        
        // NOTE: be sure to FREE ALL DYNAMIC MEMORY "A call to malloc requires a call to free() !"

        // Just to be sure when we are talking about dynamically allocating we mean the structure
        // field NOT the newNode because the structure field char* name would have to be dynamically allocated.
        // example below:

        // char* name = NULL;
        // name = (char*)malloc(sizeof(char) * KMAXSIZE);
        strcpy(head->name, data);
    }
    return head;
}

/**     -- Function header comment  [IMPORTANT:]
 *  FUNCTION        :   bEnterDataIntoHead
 *  DESCRIPTION     :   This is a function that will use a double pointer which suggest
 *                      that we can change the return type of the function and still write
 *                      into the head.
 *  PARAMETERS      :   head, data
 *  RETURNS         :   true, false
 */
const bool bEnterDataIntoHead(struct Node** head, const char* data)
{   
    // Assign to NULL then allocate.
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    // Is there space available ?
    if (newNode == NULL)
    {
        return false;
    }

    // If there is space then, we will write in the data.

    // In order to get access to the structure field we need to "cast the pointer"
    // then we will see the variable names come up.
    // Example without the function call: (*head)->name[character in name].
    strcpy((*head)->name, data);
    return true;
}

/**     -- Function header comment
 *  FUNCTION        :   showUsingPointerArithmetic
 *  DESCRIPTION     :   This function will show us the array using pointer arithmetic.
 *                      [NOTE:] This may give unexpected results, but for the most
 *                              part will work with simple concept such as displaying an array.
 *                      [NOTE:] Take note on how we are taking in the array as a parameter.
 *                      
 *                      [IMPORTANT:] Watch how you use the star in this example !!!
 *                                   I screwed up before testing I had
 *                                   printf("%i ", (*array + nums) ); the '*' being on the inside
 *                                   performs differently and wont give us our expected result.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void showUsingPointerArithmetic(int* array, const int size)
{   
    // We should always declare the variable outside of the for loop.
    int nums;
    for (nums = 0; nums < size; nums++)
    {
        printf("%i ", *(array + nums));
    }
}

/**     -- Function header comment
 *  FUNCTION        :   exitAfterFive
 *  DESCRIPTION     :   This function will exit after five iterations
 *                      we will use a status code pointer to stop the loop.
 *  PARAMETERS      :   statusCode
 *  RETURNS         :   None
 */
void exitAfterFive(int* statusCode)
{
    int start = 0;
    int end = 10;
    while (start < end)
    {
        if (start == 5)
        {   
            // Pass the status code then check it in main and
            // handle what you would like to do.

            // Maybe you were making a check after a dynamic memory allocation
            // after allocating a node and if we have found that we do NOT have
            // enough resources then we can throw the status code -1 and when in
            // main we handle it "if (statusCodeVarPassedInToFunc == -1) { return 1; }"
            *statusCode = -1;
        }
        ++start;
    }
}
