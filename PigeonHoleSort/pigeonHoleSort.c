/**
 * @file pigeonHoleSort.c
 * @author Braiden Gole
 * @brief This is the implementation of a pigeonhole sort algorithm.
 * @version 0.1
 * @date 2021-01-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "pigeonHoleSort.h"

/**     -- Function header comments
 *  FUNCTION        :   findSmallest
 *  DESCRIPTION     :   This function will find the smallest number in an
 *                      array.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   minimum
 */
int findSmallest(int* array, const int size)
{   
    int minimum = 0;
    for (int findMin = 0; findMin <= size - 1; findMin++)
    {
        if (array[findMin] < array[findMin + 1])
        {
            minimum = array[findMin];
            return minimum;
        }
    }
    return KZERO;
}

/**     -- Function header comments
 *  FUNCTION        :   findLargest
 *  DESCRIPTION     :   This function will find the largest number in an
 *                      array.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   maximum
 */
int findLargest(int* array, const int size)
{
    int maximum = 0;
    for (int findMax = 0; findMax <= size - 1; findMax++)
    {
        if (array[findMax + 1] > array[findMax])
        {
            maximum = array[findMax];
        }
    }
    return maximum;
}

/**     -- Function header comments
 *  FUNCTION        :   findRange
 *  DESCRIPTION     :   This function will calculate the range.
 *  PARAMETERS      :   max, min
 *  RETURNS         :   range
 */
const int findRange(int max, int min)
{
    int range = max - min + 1;
    return range;
}

/**     -- Function header comments
 *  FUNCTION        :   initializePigeonHoles
 *  DESCRIPTION     :   This function will initialize the pigeonholes
 *                      with NULL markers.
 *  PARAMETERS      :   holes, size
 *  RETURNS         :   None
 */
void initializePigeonHoles(int* holes, const int size)
{
    int mark = 0;
    while (mark <= size - 1)
    {
        holes[mark] = 0;
        ++mark;
    }
}

/**     -- Function header comments
 *  FUNCTION        :   fillPigeonHoles
 *  DESCRIPTION     :   This function will fill each hole.
 *  PARAMETERS      :   array, pHoles, min, range
 *  RETURNS         :   None
 */
void fillPigeonHoles(int* array, int* pHoles, int min, const int range)
{
    // Insert all elements into their holes by calculation.
    int index = 0;
    for (int numOfHoles = 0; numOfHoles <= range - 1; numOfHoles++)
    {
        index = array[numOfHoles] - min;
        pHoles[index] = array[numOfHoles];
    }
}

/**     -- Function header comments
 *  FUNCTION        :   showAllHoles
 *  DESCRIPTION     :   This function will display all of the values in
 *                      the array to the console window.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void showAllHoles(int* array, const int size)
{
    for (int nums = 0; nums < size; nums++)
    {
        printf("%i ", *(array + nums));
    }
}