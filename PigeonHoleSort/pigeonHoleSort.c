/**
 * @file pigeonHoleSort.c
 * @author Braiden Gole
 * @brief This is a spare file to write our functions in to keep the
 *        main source file nice and tidy.
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "pigeonHoleSort.h"

/**     -- Function header comment
 *  FUNCTION        :   findMinimum
 *  DESCRIPTION     :   This function will find the smallest element
 *                      in the array.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   minimum
 */
const int findMinimum(int* array, const int size)
{   
    int numbers = KZERO;
    int minimum = array[numbers __PLUS__ KONE];
    while (numbers __LSSTHAN__ size)
    {
        minimum = MIN(array[numbers], minimum);
        ++numbers;
    }
    return minimum;
}

/**     -- Function header comment
 *  FUNCTION        :   findMaximum
 *  DESCRIPTION     :   This function will find the largest element in 
 *                      the array.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   maximum
 */
const int findMaximum(int* array, const int size)
{   
    int numbers = KZERO;
    int maximum = array[numbers __PLUS__ KONE];
    while (numbers __LSSTHAN__ size)
    {
        maximum = MAX(array[numbers], maximum);
        ++numbers;
    }
    return maximum;
}

/**     -- Function header comment
 *  FUNCTION        :   pigeonHoleSort
 *  DESCRIPTION     :   This is where the function takes the holes and
 *                      will fill the original array back up with the now
 *                      sorted values.
 *  PARAMETERS      :   holes, size
 *  RETURNS         :   holes
 */
void pigeonHoleSort(int* holes, int* setOfNums, const int size, const int min)
{   
    int index = KZERO;
    int addNums = KZERO;
    for (int nums = KZERO; nums __LSSTHAN__ size; nums++)
    {   
        if (holes[nums] __NEQ__ KZERO)
        {
            setOfNums[addNums] = holes[nums];
            ++addNums;
        } 
    }
}

/**     -- Function header comment
 *  FUNCTION        :   fillHoles
 *  DESCRIPTION     :   This will fill the holes with the dat using the
 *                      calculated hole index.
 *  PARAMETERS      :   data, holeArray, size
 *  RETURNS         :   holes
 */
void fillHoles(int* data, int* holeArray, const int size, const int min)
{   
    int index = KZERO;
    for (int holes = KZERO; holes __LSSTHAN__ size; holes++)
    {
        index = data[holes] __MINUS__ min;
        holeArray[index] = data[holes];
    }
}

/**     -- Function header comment
 *  FUNCTION        :   displaySortedArray
 *  DESCRIPTION     :   This will display the sorted contents to the
 *                      console window.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void displaySortedArray(int* array, const int size)
{   
    putchar('\n');
    for (int nums = KZERO; nums __LSSTHAN__ size; nums++)
    {   
        if (array[nums] __NEQ__ KZERO)
        {
            printf("%i ", array[nums]);
        }
    }
}