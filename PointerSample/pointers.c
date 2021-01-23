/**
 * @file pointers.c
 * @author Braiden Gole
 * @brief This is an example on pointers, this will include small samples
 *        encased inside functions. 
 * 
 *      This sample is NOT for running, just view !
 * 
 *  [ FUNCTIONS TESTED ]:
 * 
 *      The only functions that are not tested are:
 *      const bool bEnterDataIntoHead(struct Node** head, const char* data);
 *      struct Node* nEnterDataIntoHead(struct Node* head, const char* data);
 * 
 *      because these are just for the sake of an example view.
 * 
 *  All the other functions were tested to make sure it was performing correctly
 *  but this sample is still just for viewing.
 * ------------------------------------------------------------------------------
 * [Read function header commments ]
 * ------------------------------------------------------------------------------
 * [IMPORTANT:] Always initialize your pointers to (NULL) !
 *              The reason why we need to initialize our pointers to
 *              null is because if we dont the variable will point at a
 *              random address in the stack which is not likely going to
 *              be the address of the variable that we are looking to manipulate.
 *              Now this only becomes an issue when you actually go and recieve
 *              input on the variable as when you do you likely wont have the right
 *              address.
 *  
 * [SOLUTION:] When we initialize our pointers to NULL for example: 
 *             char* name = NULL;
 *             and then collect input on that variable we are actually
 *             grabing the proper address because initializing to NULL gives
 *             it a spot to point to in the stack rather than "Randomly !".
 * ------------------------------------------------------------------------------
 * The examples are just used for ideas on how to use pointers and what they are
 * good for. I am not trying to write proper algorithm snippets just pointing 
 * out some situations.
 * ------------------------------------------------------------------------------
 * 
 * [NOTE:] Pointers are useful but they are sometimes dangerous in the way they behave
 *         I would recommend using them only when you absolutely have to or to say the
 *         least try to limit your use of pointers, but dont be afraid to use them.
 * @version 0.1
 * @date 2021-01-22
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Header files.
#include "pointersExample.h"

// Function prototypes.
const int indexElement(int set[], const int size, const int index);
void fillVariable(int* variableToFill);

int main(void)
{   
    //-----------------------------------------------------------------------
    // [Example 1]: Fill the index with the value you want.
    int index = 4;
    int array[KLIMIT] = { 9, 3, 8, 4, 1, 6, 5, 0, 2, 7 };
    const int resultOne = indexElement(array, KLIMIT, index);
    printf("Your value at index[%i]: %i", index, resultOne);
    // [End Example 1].
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // [Example 2]:
    // Pass in variable with &valueToFill because:

    // int* p = NULL;
    // p = &valueToFill;

    // If we were to sub in a pointer variable rather than a <-- (pointer variable) int* valueToFill = NULL;
    // regular int variable we would simply sub in the variable name.
    // like so: fillVariable(valueToFill);

    int valueToFill = 0;
    fillVariable(&valueToFill);
    printf("\nThe value has been assigned to: %i", valueToFill);

    // [End Example 2].
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // [Example 3]:
    int* code = NULL;
    exitAfterFive(code);
    
    /*
        Handle what you would like to do when the variable gets dereferenced and assigned to -1.
        inside of the exitAfterFive function. Example below.
    */

    /*
        if (code == -1)
        {
            return 1;
        }
    */
    // [End Example 3].
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // [Example 4]:
    // We can also use #define to define a constant anywhere in the program !
    // does not just have to be at the top. So NO '=' sign.
    #define KNAME "BRAIDEN"
    struct Node* head = NULL;

    bool retFourVal;
    retFourVal = nEnterDataIntoHead(head, KNAME);
    printf("%s", head->name);
    // [End Example 4].
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // [Example 5]:
    // This is a double pointer function we need to pass in a pointer to pointer.
    // int** x = NULL;
    // int* i = NULL;
    // x = &i pointer to pointer !

    bool retFiveVal;
    retFiveVal = bEnterDataIntoHead(&head, KNAME);
    printf("%s", head->name);
    // [End Example 5].
    //-----------------------------------------------------------------------

    // [Example 7]:
    showUsingPointerArithmetic(array, KLIMIT);
    // [End Example 7].
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   indexElement
 *  DESCRIPTION     :   This will get a value from an array index by a pointer.
 *  PARAMETERS      :   set, size, index
 *  RETURNS         :   element
 */
const int indexElement(int set[], const int size, const int index)
{   
    // Are we in range of the array size ?
    int value = 0;
    int* element = NULL;
    if (!(index >= 0 && index <= size))
    {
        return 1;
    }
    else
    {   
        // If so, then get the element using the index supplied.
        element = (int*)&set[index];
        value = element[0];
    }
    return value;
}

/**     -- Function header comment
 *  FUNCTION        :   fillVariable
 *  DESCRIPTION     :   This function is a demonstration on how
 *                      to use pointer we will fill a value from a
 *                      function without returning. This will fill the value
 *                      with a constant value of "9999", just for an example.
 *  PARAMETERS      :   variableToFill
 *  RETURNS         :   None
 */
void fillVariable(int* variableToFill)
{   
    *variableToFill = VALUE;
}
