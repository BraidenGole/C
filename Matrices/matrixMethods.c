/**
 * @file matrixMethods.c
 * @author Braiden Gole
 * @brief This is a program that deals with matrices.
 * @version 0.1
 * @date 2020-12-27
 * @copyright Copyright (c) 2020
 */
#include <stdio.h>
#include <stdlib.h>

// Header files.
#include "matrixMethods.h"

/**     -- Method header comment
 *  Method          :   add3x3Matrix
 *  Description     :   This function will add two matrices.
 *  Parameters      :   int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]
 *  Returns         :   result
 */
int* add3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3])
{
    int* result = NULL;
    result = (int*)malloc((KROWS3X3 * KCOLS3X3) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS3X3; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS3X3; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS3X3; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS3X3 + m1c) = matrixOne[m1r][m1c] + matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}

/**     -- Method header comment
 *  Method          :   subtract3x3Matrix
 *  Description     :   This function will subtract two matrices.
 *  Parameters      :   int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]
 *  Returns         :   result
 */
int* subtract3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3])
{
    int* result = NULL;
    result = (int*)malloc((KROWS3X3 * KCOLS3X3) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS3X3; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS3X3; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS3X3; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS3X3 + m1c) = matrixOne[m1r][m1c] - matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}

/**     -- Method header comment
 *  Method          :   multiply3x3Matrix
 *  Description     :   This function will multiply two matrices.
 *  Parameters      :   int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]
 *  Returns         :   result
 */
int* multiply3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3])
{
    int* result = NULL;
    result = (int*)malloc((KROWS3X3 * KCOLS3X3) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS3X3; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS3X3; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS3X3; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS3X3 + m1c) = matrixOne[m1r][m1c] * matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}

// Display function.
void displayMatrix(int *matrix, const int mRows, const int mCols)
{   
    printf("\n  -- Matrix %ix%i --\n", mRows, mCols);
    for (int rows = 0; rows < mRows; rows++)
    {   
        // Row == 1 for 2x2 matrix display.
        if (rows == 1) { printf("\n"); }
        // Row == 2 for 3x3 matrix display.
        if (rows == 2) { printf("\n"); }
        for (int columns = 0; columns < mCols; columns++)
        {   
            printf("\t%i  ", *((matrix + rows * mCols) + columns));
        }
    }
    printf("\n");
}