/**
 * @file selectionSort.c
 * @author Braiden Gole
 * @brief This is a selection sort implementation.
 * @version 0.1
 * @date 2021-01-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "selectionSort.h"

// Function prototypes.
void selectAndSwap(int* value, int* swapWith);

/**     -- Function header comment
 *  FUNCTION        :   sortSelection
 *  DESCRIPTION     :   This is the function that will perform the selection sort.
 *  PARAMETERS      :   smallSet, size
 *  RETURNS         :   None
 */
void sortSelection(int* smallSet, const int size)
{   
    int nums = KZERO;
    int sort = KZERO;
    int minimumIndex = KZERO;

    while (sort __LESSTHAN__ size)
    {   
        minimumIndex = sort;
        nums = (sort __PLUS__ KONE);
        while (nums __LESSTHAN__ size)
        {
            if (smallSet[nums] __LESSTHAN__ smallSet[minimumIndex])
            {
                minimumIndex = nums;
            }
            ++nums;
        }
        // Move the smallest number to the begining.
        selectAndSwap(&smallSet[minimumIndex], &smallSet[sort]);
        ++sort;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   selectAndSwap
 *  DESCRIPTION     :   This function will swap two values.
 *  PARAMETERS      :   value, swapWith
 *  RETURNS         :   None
 */
void selectAndSwap(int* value, int* swapWith)
{   
    int temp = KZERO;
    SWAP(temp, *value, *swapWith);
}

/**     -- Function header comment
 *  FUNCTION        :   showSelection
 *  DESCRIPTION     :   This is a function to display the final product.
 *  PARAMETERS      :   smallSet, size
 *  RETURNS         :   None
 */
void showSelection(int smallSet[], const int size)
{   
    int data = KZERO;
    do
    {
        printf("%i ", smallSet[data]);
        ++data;
    } while (data __LESSTHAN__ size);
}