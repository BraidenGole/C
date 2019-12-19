/*
    FILE            :   binarySearch.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2019-12-19
    DESCRIPTION     :   This is the implementation of the binary search algorithm.
*/
#include <stdio.h>

#define KMAX_NUMBER_LEN 301

// Function Prototypes.
short binarySearch(int sortedArray[], int* desiredNumber);

int main(void)
{   
    // Initialize an array with sorted numbers.
    int myNumbers[KMAX_NUMBER_LEN] = { 0 };
    short numbers = 0;

    // This array of sorted ints start at 0 to 300.
    for (numbers; numbers < KMAX_NUMBER_LEN; ++numbers)
    {
        myNumbers[numbers] = numbers;
    }

    // Prompt user for the (desiredNumber).
    int desiredNumber = 0; short convertedSuccessfully = 0;
    do
    {
        printf("Please enter in a number from 0 - %i : ", KMAX_NUMBER_LEN - 1);
        if (convertedSuccessfully = (fscanf(stdin, "%i", &desiredNumber) != 1))
        {
            fprintf(stderr, "\nInvalid input! Please try again.\n");
            return 1;
        }
    } while ((desiredNumber < 0 && desiredNumber < KMAX_NUMBER_LEN) && 
    (convertedSuccessfully != 1));
    
    // Function call to the function binarySearch.
    if (binarySearch(myNumbers, &desiredNumber) != 0)
    {
        fprintf(stderr, "\nYour item was not found !\n");
        return 1;
    }
    else
    {   
        printf("\nYour item exists and index: [%i]\n", desiredNumber);
    }
    return 0;
}

/*
    FUNCTION        :   binarySearch
    DESCRIPTION     :   This function takes in a sortedArray[] as input and will iterate
                        through the sequence of elements starting from the (middle)
                        KMAX_NUMBER_LEN / 2 == (middle).
    PARAMETERS      :   sortedArray
    RETURNS         :   0, 1
*/
short binarySearch(int sortedArray[], int* desiredNumber)
{   
    // Get the center index to get the middle element.
    int middle = KMAX_NUMBER_LEN / 2; short start = 0;
    while (start < KMAX_NUMBER_LEN)
    {   
        if (sortedArray[middle] == *desiredNumber)
        {   
            *desiredNumber = middle;
            return 0;
        }
        else if (sortedArray[middle] < *desiredNumber)
        {   
            if (sortedArray[++middle] == *desiredNumber)
            {   
                *desiredNumber = middle;
                return 0;
            }
        }
        else if (sortedArray[middle] > *desiredNumber)
        {   
            if (sortedArray[--middle] == *desiredNumber)
            {   
                *desiredNumber = middle;
                return 0;
            }
        }
        ++start;
    }
    return 1;
}