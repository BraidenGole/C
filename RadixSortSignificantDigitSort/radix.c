/**
 * @file radix.c
 * @author Braiden Gole
 * @brief This is a radix sort implementation.
 * ---------------------------------------------------------------------
 * (Learned the ins and outs of a radix sort algorithm (GeeksForGeeks))
 * [SOURCE/WEBSITE]: https://www.geeksforgeeks.org/radix-sort/
 * ---------------------------------------------------------------------
 * [IMPORTANT]
 * Be careful what you sub in as far as numbers they should likely be under
 * 5 digits in length, the reason for this is the algorithm itself.
 *----------------------------------------------------------------------
 * @version 0.1
 * @date 2021-03-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "radixSort.h"

// Function prototypes.
void displaySet(int* array, const int size);

int main(void)
{
    int set[TEN] = { 412, 19, 10, 27, 62, 89, 16, 48, 52, 30 };
    int max = ZERO;

    int* newSet = NULL;
    max = retrieveMaximum(set, TEN);

    int places = ONE;
    do
    {   
        newSet = countingSort(set, TEN, places);

        // Controls how many digits we break off of the max number it
        // also controls what current digit place we are sitting at.
        places *= TEN;
    } while ((max / places) __LRG__ ZERO);
    
    // Display the sorted set of elements.
    displaySet(newSet, TEN);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   displaySet
 *  DESCRIPTION     :   This will display all the sorted elements in the set.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void displaySet(int* array, const int size)
{
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {
        printf("%i ", *(array + nums));
    }
}
