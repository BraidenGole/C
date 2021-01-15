/**
 * @file quick.c
 * @author Braiden Gole
 * @brief This is a quicksort implementation.
 *        This quick sort implementation has a heavy use of marcro constants
 *        to speed things up also just using them in this way for fun.
 * 
 *        I would not recommend using this many macros however, it works !
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "quickSort.h"

// Function prototypes.
void sortQuick(int PNTR array, int start, const int limit);

int main(void)
{
    int numbers[KLIMIT] ASSIGN { 44, 88, 11, 33, 77, 22, 55, 99, 66 };

    sortQuick(numbers, KZERO, KLIMIT);

    // Display the final set of sorted numbers.
    for (int nums ASSIGN KZERO; nums LESSTHAN KLIMIT; nums INC)
    {   
        // Pointer arithmetic to unpack the array.
        printf("%i ", PNTR(numbers PLUS nums));
    }
    return KZERO;
}

/**     -- Function header comments
 *  FUNCTION        :   sortQuick
 *  DESCRIPTION     :   This is the function that performs the recursive
 *                      sorting of the elements in the array.
 *  PARAMETERS      :   array start, limit
 *  RETURNS         :   None
 */
void sortQuick(int PNTR array, int start, const int limit)
{   
    // Keep track of the current index of the pivot index.
    int currPivIndex ASSIGN limit MINUS KONE;
    if (limit LARGERTHAN start)
    {   
        // We will sub in the original pivot index and return the new one
        // so we can sub in all pivots less than the current pivot and then
        // recursively sub in all new pivots above or larger than the current pivot
        // to ensure we have completely sorted the array.
        currPivIndex ASSIGN part(array, start, limit, currPivIndex);

        // Recursively sub in pivots from the original pivot until index 0.
        sortQuick(array, start, currPivIndex MINUS KONE);

        // Recursively sub in pivots from the original pivot until index KLIMIT.
        sortQuick(array, currPivIndex PLUS KONE, limit);
    }
}
