/**
 * @file fibSearch.c
 * @author Braiden Gole
 * @brief This is a fibonacci Search implementation.
 * @version 0.1
 * @date 2021-06-11
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Function prototypes.
int fibonacciSearch(int array[], int size, int find);
int generateFibSequence(int* fibTwo, int* fibOne, int size);
int cutLeftRange(int* fibTwo, int* fibOne, int result, int* offset, int* min);
void cutRightRange(int* fibTwo, int* fibOne, int* result);

int main(void)
{
    int arrayOfNumbers[] = {10, 23, 28, 42, 51, 56, 60, 65, 103, 110, 138};
    int sizeOfSet = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    int findMe = 51;
    int foundIndex = fibonacciSearch(arrayOfNumbers, sizeOfSet, findMe);
    printf("Your number was found at index: %i", foundIndex);
}

/**     -- Function header comment
 *  FUNCTION        :   fibonacciSearch
 *  DESCRIPTION     :   This function will perform a fibonacci search on a given arrays
 *  PARAMETERS      :   array, size, find
 *  RETURNS         :   minimum, -1
 */
int fibonacciSearch(int array[], int size, int find)
{
    int fibOne = 1;
    int fibTwo = 0;
    int offset = -1;
    int result;
    result = generateFibSequence(&fibTwo, &fibOne, size);

    do
    {
        // Boundry checking.
        // Using offset to skip values that we do not need to check.
        int minimum = MIN(offset + fibTwo, size - 1);
        if (array[minimum] < find)
        {   
            // Eliminate numbers from the left side.
            result = cutLeftRange(&fibTwo, &fibOne, result, &offset, &minimum);
        }
        else if (array[minimum] > find)
        {   
            // Eliminate numbers from the right side.
            cutRightRange(&fibTwo, &fibOne, &result);
        }
        else
        {
            return minimum;
        }
    } while (result > 1);
    if (fibOne && array[offset + 1] == find)
    {
        return offset;
    }
    return -1;
}

/**     -- Function header comment
 *  FUNCTION        :   genereateFibSequence
 *  DESCRIPTION     :   This function will generate fib numbers up to the size.
 *  PARAMETERS      :   fibTwo, fibOne, size
 *  RETURNS         :   result
 */
int generateFibSequence(int* fibTwo, int* fibOne, int size)
{   
    int result = *fibTwo + *fibOne;
    do 
    {
        *fibTwo = *fibOne;
        *fibOne = result;
        result = *fibTwo + *fibOne;
    } while (result < size);
    return result;
}

/**     -- Function header comment
 *  FUNCTION        :   cutLeftRange
 *  DESCRIPTION     :   This will eliminate numbers that sit to the left of the number to find.
 *  PARAMETERS      :   fibTwo, fibOne, result, offset, min
 *  RETURNS         :   result
 */
int cutLeftRange(int* fibTwo, int* fibOne, int result, int* offset, int* min)
{
    result = *fibOne;
    *fibOne = *fibTwo;
    *fibTwo = result - *fibOne;
    *offset = *min;
    return result;
}

/**     -- Function header comment
 *  FUNCTION        :   cutRightRange
 *  DESCRIPTION     :   This will eliminate numbers that sit to the right of the number to find.
 *  PARAMETERS      :   fibTwo, fibOne, result
 *  RETURNS         :   None
 */
void cutRightRange(int* fibTwo, int* fibOne, int* result)
{
    *result = *fibTwo;
    *fibOne = *fibOne - *fibTwo;
    *fibTwo = *result - *fibOne;
}
