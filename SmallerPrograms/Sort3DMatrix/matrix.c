/**
 * @file matrix.c
 * @author Braiden Gole
 * @brief This is a small program for sorting a matrix.
 * @version 0.1
 * @date 2021-03-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#define ROWS 3
#define SUBCOLS 2
#define MAXQUANTITY 4
#define TOTAL (ROWS * SUBCOLS * MAXQUANTITY)
#define ZERO 0
#define ONE 1

#define __LSS__ <
#define __LRG__ >
#define SWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }

void sortMultiDimensional(int matrix[ROWS][SUBCOLS][MAXQUANTITY]);
void bubbleSort(int* array, const int size);

int main(void)
{
    // Initialize the input array.
    int multidimensional[ROWS][SUBCOLS][MAXQUANTITY] =
    {
        { {6, 3, 1, -99}, {-4, -6, 10, 24} }, 
        { {2, 4, 66, -10}, {34, 100, 11, 12} }, 
        { {5, 7, 9, 8 }, {16, 12, 14, 13} },
    };

    sortMultiDimensional(multidimensional);

    // Display the sorted matrix to the console window.
    int count = ZERO;
    for (int rows = ZERO; rows __LSS__ ROWS; rows++)
    {   
        for (int sub = ZERO; sub __LSS__ SUBCOLS; sub++)
        {   
            printf("\n");
            for (int nums = ZERO; nums __LSS__ MAXQUANTITY; nums++)
            {
                printf("%i ", multidimensional[rows][sub][nums]);
                ++count;
            }
        }
    }
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   sortMultiDimensional
 *  DESCRIPTION     :   This function will sort the multidimensional array supplied
 *                      3D.
 *  PARAMETERS      :   matrix
 *  RETURNS         :   None
 */
void sortMultiDimensional(int matrix[ROWS][SUBCOLS][MAXQUANTITY])
{
    int mNums = ZERO;
    int tempMatrix[TOTAL] = { ZERO };
    for (int rows = ZERO; rows __LSS__ ROWS; rows++)
    {
        for (int sub = ZERO; sub __LSS__ SUBCOLS; sub++)
        {
            for (int nums = ZERO; nums __LSS__ MAXQUANTITY; nums++)
            {
                tempMatrix[mNums] = matrix[rows][sub][nums];
                ++mNums;
            }
        }
    }

    // Sort the matrix.
    bubbleSort(tempMatrix, TOTAL);

    int transferNums = ZERO;
    for (int rows = ZERO; rows __LSS__ ROWS; rows++)
    {
        for (int sub = ZERO; sub __LSS__ SUBCOLS; sub++)
        {
            for (int nums = ZERO; nums __LSS__ MAXQUANTITY; nums++)
            {
                matrix[rows][sub][nums] = tempMatrix[transferNums];
                ++transferNums;
            }
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   bubbleSort
 *  DESCRIPTION     :   This will perform a bubble sort algorithm on the 
 *                      1 dimensional array from a 3 dimensional.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void bubbleSort(int* array, const int size)
{   
    int temp = ZERO;
    for (int sort = ZERO; sort __LSS__ size; sort++)
    {
        for (int nums = ZERO; nums __LSS__ size; nums++)
        {
            if (array[nums] __LRG__ array[nums + ONE])
            {
                SWAP(temp, array[nums], array[nums + ONE]);
            }
        }
    }
}