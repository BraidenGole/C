/**
 * @file select.c
 * @author Braiden Gole
 * @brief This is a selection sort implementation.
 * 
 *      NOTE: Changing my programming style slightly for a change.
 * 
 * @version 0.1
 * @date 2021-01-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "selectionSort.h"

// Function prototype.
void selectAndSwap(int* value, int* swapWith);

int main(void)
{
    int smallSetOfNums[KSIZE] = { -90, 235, 16, 36, 15, 8, 12, -943, 133, 223, 66, -30 };
    sortSelection(smallSetOfNums, KSIZE);
    showSelection(smallSetOfNums, KSIZE);
    return KZERO;
}