/**
 * @file search.c
 * @author Braiden Gole
 * @brief This is a Ternary Search implementation.
 * @version 0.1
 * @date 2021-06-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Function prototypes.
int ternarySearch(int array[], int start, int end, int searchKey);

int main(void)
{   
    int setOfNumbers[] = { 12, 24, 36, 40, 41, 44, 56, 58, 59, 63, 65, 69 };
    int startingPoint = 0;
    int endingPoint = sizeof(setOfNumbers) / sizeof(setOfNumbers[0]);
    int findMe = 12;
    
    int foundIndex;
    foundIndex = ternarySearch(setOfNumbers, startingPoint, endingPoint, findMe);
    if (foundIndex != -1)
    {
        printf("Your number was found at: %i", foundIndex);
    }
    else
    {
        printf("Your number was not found !");
    }
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   ternarySearch
 *  DESCRIPTION     :   This function will perform the arithmetic to a ternary search.
 *  PARAMETERS      :   array, start, end, searchKey
 *  RETURNS         :   middleOne, middleTwo, -1
 */
int ternarySearch(int array[], int start, int end, int searchKey)
{   
    int middleOne;
    int middleTwo;
    do
    {
        middleOne = start + (end - start) / 3;
        middleTwo = end - (end - start) / 3;
        
        if (array[middleOne] == searchKey)
        {
            return middleOne;
        }
        if (array[middleTwo] == searchKey)
        {
            return middleTwo;
        }

        if (array[middleOne] > searchKey)
        {
            end = middleOne - 1;
        }
        else if (array[middleTwo] < searchKey)
        {
            start = middleTwo + 1;
        }
        else
        {
            start = middleOne + 1;
            end = middleTwo - 1;
        }
    } while (start <= end);
    return -1;
}