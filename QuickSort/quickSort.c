/**
 * @file quickSort.c
 * @author Braiden Gole
 * @brief This is a quick sort implementation.
 * @version 0.1
 * @date 2021-01-10
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header file.
#include "quickSort.h"

/**     -- Function header comment
 *  FUNCTION        :   part
 *  DESCRIPTION     :   This function will part the array, everything less
 *                      than the pivot will go to the left of the pivot and
 *                      everything larger than the pivot will go to the right of
 *                      the pivot.
 *  PARAMETERS      :   array, size, pivot
 *  RETURNS         :   None
 */
int part(int* array, int start, int end)
{   
    int temp = 0;
    int pointer = 0;
    int pivot = array[end - 1];
    int nums = 0;

    nums = start;
    while (nums < end)
    {
        if (pivot > array[nums])
        {   
            KEXCHANGE(temp, array[pointer], array[nums]);
            ++pointer;
        }
        ++nums;
    }
    // Swap the ends after the sequence.
    KEXCHANGE(temp, array[pointer], array[end - 1]);
    return pointer;
}

/**     -- Function header comment
 *  FUNCTION        :   output
 *  DESCRIPTION     :   This function will output the array to the console.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void output(int* array, const int size)
{
    for (int nums = 0; nums < size; nums++)
    {
        printf("%i ", *(array + nums));
    }
}