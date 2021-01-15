/**
 * @file quickSort.c
 * @author Braiden Gole
 * @brief This is where we will write our partitioning method. We are using 
 *        another file to keep main() clean and tidy.
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "quickSort.h"

/**     -- Function header comments
 *  FUNCTION        :   part
 *  DESCRIPTION     :   This function will part the array so that everything
 *                      less than the pivot remians of the left hand side and 
 *                      anything larger than the pivot is on the right side.
 *  PARAMETERS      :   array, start, limit
 *  RETURNS         :   tracerIndex
 */
int part(int PNTR array, int start, const int limit, int pivotIndex)
{
    int temp ASSIGN KZERO;
    int tracer ASSIGN KZERO;
    int part ASSIGN KZERO;

    int pivot ASSIGN array[pivotIndex];
    while (part LESSTHAN limit)
    {
        if (array[part] LESSTHAN pivot)
        {   
            KEXCHANGE(temp, array[tracer], array[part]);
            INC tracer;
        }
        INC part;
    }
    // Exchange the last elements after the sequence has finished.
    KEXCHANGE(temp, array[tracer], array[limit MINUS KONE]);
    return tracer;
}