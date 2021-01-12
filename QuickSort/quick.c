/**
 * @file quick.c
 * @author Braiden Gole
 * @brief This is a quick sort implementation.
 * @version 0.1
 * @date 2021-01-10
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "quickSort.h"

// Function prototypes.
void qSort(int* array, int start, int end);

int main(void)
{   
    int simpleArray[KLIMIT] = { 44, 99, 32, 55, 3, 11, 6, -7, 89 };
    qSort(simpleArray, 0, KLIMIT);
    output(simpleArray, KLIMIT);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   qSort
 *  DESCRIPTION     :   This is a quick sort algorithm function.
 *  PARAMETERS      :   array, start, end
 *  RETURNS         :   None
 */
void qSort(int* array, int start, int end)
{
    int sort = 0;
    int pivotIndex;
    while (sort < end)
    {   
        pivotIndex = part(array, start, end);
        part(array, start, end);
        --end;
        ++sort;
    }
}