/**
 * @file radixSort.c
 * @author Braiden Gole
 * @brief Sorting by significant digit a radix sort implementation.
 * @version 0.1
 * @date 2021-03-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header file.
#include "radixSort.h"

/**     -- Function header comment
 *  FUNCTION        :   retrieveMaximum
 *  DESCRIPTION     :   This will go through all of the elements and
 *                      determine the largest value in the set.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
const int retrieveMaximum(int* array, const int size)
{   
    int nums = ZERO;
    int maximum = array[nums + ONE];
    while (nums __LSS__ size)
    {
        maximum = MAX(array[nums], maximum);
        ++nums;
    }
    return maximum;
}

/**     -- Function header comment
 *  FUNCTION        :   countingSort
 *  DESCRIPTION     :   This is a counting sort algorithm commonly implemented with
 *                      a radix sort as a subroutine.
 *  PARAMETERS      :   array, size, digitPlace
 *  RETURNS         :   None
 */
int* countingSort(int* array, const int size, int digitPlace)
{
    int final[TEN] = { ZERO };
    int holes[TEN] = { ZERO };

    int index = ZERO;
    int item = ZERO;

    int place;
    for (place = ZERO; place __LSS__ size; place++)
    {
        index = (array[place] / digitPlace) % TEN;
        holes[index] += ONE;
    }

    // Shift all positions so we can start at [0].
    for (place = ONE; place __LSS__ size; place++)
    {
        holes[place] += holes[place - ONE];
    }

    for (place = size - ONE; place __LRGEQ__ ZERO; place--)
    {
        index = (array[place] / digitPlace) % TEN;
        item = holes[index] - ONE;
        final[item] = array[place];
        holes[index] += NEGATIVEONE;
    }

    // Transfer the sorted contents to the original array.
    for (place = ZERO; place __LSS__ size; place++)
    {
        array[place] = final[place];
    }
    return array;
}