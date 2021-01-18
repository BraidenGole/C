/**
 * @file exponentialSearch.c
 * @author Braiden Gole
 * @brief This is a exponential search algorithm.
 * @version 0.1
 * @date 2021-01-17
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

// Header files.
#include "exponentialSearch.h"

/**     -- Function header comment
 *  FUNCTION        :   binarySearch
 *  DESCRIPTION     :   This is a binary search algorithm that we will be calling in order
 *                      to complete our exponential search.
 *  PARAMETERS      :   data, size, searchTearm, midIndex
 *  RETURNS         :   found(true, false)
 */
const bool binarySearch(int* data, int iter, int size, const int searchTerm)
{   
    const int midIndex = iter __PLUS__ (size __MINUS__ iter) __DIV__ TWO;
    bool found = false;

    // Sanity check is it the first term ?
    if (data[ZERO] __EQ__ searchTerm)
    {
        found = true;
        return found;
    }
    
    // Checking to see which loop we send it to based on its index.
    // We can only do this because this is a search algorithm which suggest
    // that we must have a sorted set of elements to begin with.
    if (searchTerm __LSS_EQ__ data[midIndex])
    {
        int nums = ZERO;
        while (nums __LSS_EQ__ midIndex)
        {   
            if (data[nums] __EQ__ searchTerm)
            {   
                found = true;
                return found;
            }
            ++nums;
        }
    }
    
    int otherSide = midIndex __PLUS__ ONE;
    while (otherSide __LSS__ size)
    {
        if (data[otherSide] __EQ__ searchTerm)
        {   
            found = true;
            return found;
        }
        ++otherSide;  
    }
    return found;
}

/**     -- Function header comment
 *  FUNCTION        :   generatePowIndex
 *  DESCRIPTION     :   This will generate the index to sub into the binary
 *                      search function and we will write the result of this
 *                      function into a variable passed in as a resulting variable.
 *  PARAMETERS      :   data, max, value, result
 *  RETURNS         :   None
 */
void generatePowIndex(int* data, const int max, const int value, int* result)
{   
    // Different styled loop & logic for a change, not the best style but works.
    for (; (*result __LSS__ max) AND (data[*result] __LSS_EQ__ value) ;)
    {   
        RECURPOW(*result);
    }
}

/**     -- Function header comment
 *  FUNCTION        :   show
 *  DESCRIPTION     :   This function will print the array to the console window.
 *  PARAMETERS      :   data, size
 *  RETURNS         :   None
 */
void show(int* data, const int size)
{   
    const char space = ' ';
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {
        printf(_INT_FORMAT _CHAR_FORMAT, data[nums], space);
    }
}
