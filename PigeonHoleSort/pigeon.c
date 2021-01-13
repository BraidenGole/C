/**
 * @file pigeon.c
 * @author Braiden Gole
 * @brief This is the implementation of a pigeonhole sort algorithm.
 * @version 0.1
 * @date 2021-01-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

// Header files.
#include "pigeonHoleSort.h"

// Function prototypes.
void pigeonHoleSort(int* array, int* holes, const int range);

int main(void)
{      
    int numbers[KSIZE] = { 5, 3, 2, 1, 4, 6, 7, 9, 8 };
    
    int max = findLargest(numbers, KSIZE);
    int min = findSmallest(numbers, KSIZE);
    const int range = findRange(max, min);

    printf("\n  -- Summary --");
    printf("\n\tMax: %i\n", max);
    printf("\tMin: %i\n", min);
    printf("\tRange: %i\n\n", range);

    // Dynamically allocate the holes.
    int* holes = NULL;
    holes = (int*)malloc(sizeof(int) * range);
    if (holes == NULL)
    {   
        fprintf(stderr, "\n\tNo memory left !\n");
        return 0;
    }

    // Initialize then fill the pigeon holes with the numbers.
    initializePigeonHoles(holes, range);
    fillPigeonHoles(numbers, holes, min, range);

    // Sort then display all of the values.
    pigeonHoleSort(numbers, holes, range);
    showAllHoles(numbers, range);

    // Make sure we take care of freeing resources.
    free(holes);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   pigeonHoleSort
 *  DESCRIPTION     :   This is the function that will put the elements
 *                      back into the array in sorted order.
 *  PARAMETERS      :   array, holes, range
 *  RETURNS         :   None
 */
void pigeonHoleSort(int* array, int* holes, const int range)
{   
    int nums = 0;
    int index = 0;
    for (int sort = 0; sort < range; sort++)
    {
        if (holes[sort] != 0)
        {
            array[index] = holes[sort];
            ++index;
        }
    }
}
