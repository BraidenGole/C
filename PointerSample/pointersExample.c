/**
 * @file pointersExample.c
 * @author Braiden Gole
 * @brief This is a file used to write more examples on pointers.
 * @version 0.1
 * @date 2021-01-22
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

// Header file.
#include "pointersExample.h"

/**     -- Function header comment
 *  FUNCTION        :   showUsingPointerArithmetic
 *  DESCRIPTION     :   This function will print our array using pointer arithmetic.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void showUsingPointerArithmetic(int* array, const int size)
{   
    int nums;
    for (nums = 0; nums < size; nums++)
    {
        printf("%i ", *(array + nums));
    }
}

/**     -- Function header comment
 *  FUNCTION        :   showByIncrementingPointer
 *  DESCRIPTION     :   This function will show the list of elements
 *                      by incrementing the pointer supplied.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void showByIncrementingPointer(int* array, const int size)
{
    int nums;
    for (nums = 0; nums < size; nums++)
    {
        printf("%i ", *array);

        // We are actually incrementing the pointer rather
        // that the iterable variable in this example.
        ++array;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   castToAsciiChar
 *  DESCRIPTION     :   This function will cast the value of the index supplied to
 *                      its ascii character value.
 *  PARAMETERS      :   symbol
 *  RETURNS         :   None 
 */
const char* castToAsciiChar(int array[KLIMIT], const int size, const int index)
{   
    int* element = NULL;
    element = (int*)&array[index];

    char* value = NULL;
    value = (char*)element;
    return value;
}