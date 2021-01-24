/**
 * @file pointers.c
 * @author Braiden Gole
 * @brief This is an example on pointers. 
 * -------------------------------------------------------------------------------------------
 * [ Visit more projects in C if you want to see more samples on the application of pointers ]
 * -------------------------------------------------------------------------------------------
 * [IMPORTANT:] Always initialize your pointers to (NULL).
 * 
 *              The reason why we need to initialize our pointers to
 *              null is because if we dont the variable will point at a
 *              random address in the stack which will NOT be the address of the 
 *              variable that we are looking to manipulate.
 *  
 * [SOLUTION:] If we initialize our pointer to NULL like the example below: 
 * 
 *             char* name = NULL;
 * 
 *             Then we will have a spot to point to in the stack rather than randomly and
 *             this will be the spot that belongs to the variable.
 * -----------------------------------------------------------------------------------
 * [NOTE:] Pointers are very useful but they can be quite dangerous and their
 *         behaviour can be hard to track in specific situations you are best use
 *         pointers more less when you have to. Do not be afraid to use pointers
 *         they help with performace, data flow, and access within our program.
 * -----------------------------------------------------------------------------------
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
    // Fill in the index value of the value you want in the array.
    int index = 4;
    int array[KLIMIT] = { 9, 3, 8, 4, 1, 6, 5, 0, 2, 7 };
    const int resultOne = indexElement(array, KLIMIT, index);
    printf("Your value at index[%i]: %i", index, resultOne);

    // Lets fill a variable with a fixed value.
    int valueToFill = 0;
    fillVariable(&valueToFill);
    printf("\nThe value has been assigned to: %i\n", valueToFill);

    // Print using pointer arithmetic.
    showUsingPointerArithmetic(array, KLIMIT);

    putchar('\n');

    // Print by incrementing the pointer.
    showByIncrementingPointer(array, KLIMIT);

    // As of right now it will print a smiley face and that is correct.
    printf("\nThis is the ascii casted character: %s", castToAsciiChar(array, KLIMIT, index));
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   indexElement
 *  DESCRIPTION     :   This will get a value from an array indexed by a pointer.
 *  PARAMETERS      :   set, size, index
 *  RETURNS         :   value
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
 *  DESCRIPTION     :   This function will fill a variable passed in
 *                      without returning the variable.
 *  PARAMETERS      :   variableToFill
 *  RETURNS         :   None
 */
void fillVariable(int* variableToFill)
{   
    *variableToFill = VALUE;
}