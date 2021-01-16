/**
 * @file pigeon.c
 * @author Braiden Gole
 * @brief This is a pigeonhole sort implementation.
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

// Header file.
#include "pigeonHoleSort.h"

// Function prototypes.
void initializeHoles(int* array, const int size);

int main(void)
{   
    // Make sure when initializing this array that we use a power of 2 for the total
    // number of elements in the array otherwise it will not work.
    int set[KMAXSIZE] = { 3, 63, -94, 9, 5, 2, 4, 1, 8, 7, -10, -78, 36, 11, -30, 99 };

    // Find the smallest and largest elements of the set.
    int min = findMinimum(set, KMAXSIZE);
    int max = findMaximum(set, KMAXSIZE);

    // This macro will assign the range passed in as a variable.
    int range = KZERO;
    RANGE(range, max, min);

    printf("\n -- Pigeonhole sort summary --\n");
    printf("\tMin: %i\n", min);
    printf("\tMax: %i\n", max);
    printf("\tRange: %i\n", range);

    // Create a dynamically allocated space for the pigeonholes.
    // The size of this array will depend upon the calculated range !
    int* pigeonHoles = NULL;
    const int KSIZEOFHOLES = range;

    // Allocate then check to see if we have the memory to allocate.
    pigeonHoles = (int*)malloc(sizeof(int) * KSIZEOFHOLES);
    if (pigeonHoles __EQ__ NULL)
    {
        fprintf(stderr, KOUTOFMEM);
        return KONE;
    }
    else
    {   
        // Now allocated, fill holes with KZERO to indicate that the the holes are empty.
        initializeHoles(pigeonHoles, KSIZEOFHOLES);
        fillHoles(set, pigeonHoles, KMAXSIZE, min);
        
        // Unpack the holes now that the numbers are sorted and put them
        // back into the original array to complete the "pigeon hole sort".
        pigeonHoleSort(pigeonHoles, set, KSIZEOFHOLES, min);
        displaySortedArray(set, KMAXSIZE);
    }

    // Before ending the program make sure we clean up any allocated memory.
    free(pigeonHoles);
    return KZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   initializeHoles
 *  DESCRIPTION     :   This will initialize all the holes with a zero.
 *  PARAMETERS      :   array, size
 *  RETRUNS         :   None
 */
void initializeHoles(int* array, const int size)
{
    for (int holes = KZERO; holes __LSSTHAN__ size; holes++)
    {
        *(array __PLUS__ holes) = KZERO;
    }
}