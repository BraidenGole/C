/**
 * @file binarySearch.c
 * @author Braiden Gole
 * @brief This is a binary search implementation.
 * @version 0.1
 * @date 2021-06-13
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#define SEARCHLIMIT 10

// Function prototypes.
int binarySearch(int array[], int size, int searchKey);

int main(void)
{
    int searchArray[SEARCHLIMIT] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int foundIndex;
    foundIndex = binarySearch(searchArray, SEARCHLIMIT, 1);

    if (foundIndex == -1)
    {
        printf("NOT FOUND !");
    }
    else
    {
        printf("Your number has been found at %i", foundIndex);
    }

    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   binarySearch
 *  DESCRIPTION     :   This function will repeatedly divide the search interval in half
 *                      narrowing results as the iterative process goes on until a match or no match.
 *  PARAMETERS      :   array, size, searchKey
 *  RETURNS         :   middle, -1
 */
int binarySearch(int array[], int size, int searchKey)
{
    int start = 0;
    int middle = 0;
    int end = SEARCHLIMIT - 1;

    do
    {
        middle = (start + end) / 2;
        if (array[middle] < searchKey)
        {
            start = middle + 1;
        }
        else if (array[middle] > searchKey)
        {
            end = middle - 1;
        }
        else
        {
            return middle;
        }
    } while (start <= end);
    return -1;
}