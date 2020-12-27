/**
 * @file matrix2x2.c
 * @author Braiden Gole
 * @brief This is a program that deals with matrices.
 * @version 0.1
 * @date 2020-12-27
 * @copyright Copyright (c) Braiden Gole 2020
 */
#include <stdio.h>
#include <stdlib.h>

// Header files.
#include "matrixMethods.h"

/**     -- Method header comment
 *  Method          :   add2x2Matrix
 *  Description     :   This function will add two matrices.
 *  Parameters      :   int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]
 *  Returns         :   result
 */
int* add2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2])
{   
    int* result = NULL;
    result = (int*)malloc((KROWS2X2 * KCOLS2X2) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS2X2; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS2X2; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS2X2; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS2X2 + m1c) = matrixOne[m1r][m1c] + matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}

/**     -- Method header comment
 *  Method          :   subtract2x2Matrix
 *  Description     :   This function will subtract two matrices.
 *  Parameters      :   int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]
 *  Returns         :   result
 */
int* subtract2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2])
{   
    int* result = NULL;
    result = (int*)malloc((KROWS2X2 * KCOLS2X2) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS2X2; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS2X2; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS2X2; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS2X2 + m1c) = matrixOne[m1r][m1c] - matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}

/**     -- Method header comment
 *  Method          :   multiply2x2Matrix
 *  Description     :   This function will add multiply two matrices.
 *  Parameters      :   int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]
 *  Returns         :   result
 */
int* multiply2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2])
{   
    int* result = NULL;
    result = (int*)malloc((KROWS2X2 * KCOLS2X2) * sizeof(int));
    if (result == NULL) { return NULL; }

    // m1r = Matrix 1 row.
    // m2c = Matrix 2 column.
    // m1c = Matrix 1 column.
    for (int m1r = 0; m1r < KROWS2X2; m1r++)
    {
        for (int m2c = 0; m2c < KCOLS2X2; m2c++)
        {
            for (int m1c = 0; m1c < KCOLS2X2; m1c++)
            {   
                // Pointer arithmetic.
                *(result + m1r * KCOLS2X2 + m1c) = matrixOne[m1r][m1c] * matrixTwo[m1c][m2c];
            }
        }
    }
    return result;
}