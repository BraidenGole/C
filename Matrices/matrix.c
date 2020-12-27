/**
 * @file matrix.c
 * @author Braiden Gole
 * @brief This is a program that deals with matrices.
 *        NOTE: This program was a learning experience I wanted to perform
 *              some simple operations to a 3x3 matrix and 2x2 matrix I got confused
 *              and later realized that I did not have to individually cater to each
 *              3x3 matrix or 2x2 matrix operations even if we are performing 
 *              operations of 2 matrices at the same time such as the: ADD, SUBTRACT, MULTIPLY, methods.
 * 
 *        NOTE: The main source of the issue was I thought of a 2x2 and 3x3 matrix as a 2 dimensional programming array
 *              and a 3 dimensional programming array. Instead it is a fixed 2 dimensional array either containing 3 rows
 *              3 columns or 2 rows 2 columns.
 * 
 *        NOTE: I did not calculate the sizes of each matrix because I only had the goal to cater to 2x2 and 3x3 matrices.
 * @version 0.1
 * @date 2020-12-27
 * @copyright Copyright (c) 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header files.
#include "matrixMethods.h"

// Function prototypes.

/**********************************/
// Initialize your 2x2 matrices.
/**********************************/
int matrixA_2x2[KROWS2X2][KCOLS2X2] = 
{
    {3, 5},
    {-7, 8},
};

int matrixB_2x2[KROWS2X2][KCOLS2X2] = 
{
    {7, 1},
    {2, 9},
};

/**********************************/
// Initialize your 3x3 matrices.
/**********************************/
int matrixA_3x3[KROWS3X3][KCOLS3X3] = 
{
    {1, 3, 2},
    {4, 1, 3},
    {2, 5, 2},
};

int matrixB_3x3[KROWS3X3][KCOLS3X3] = 
{
    {1, 1, 1},
    {2, -3, 1},
    {3, -1, 4},
};

int main(void)
{   
    // Delcare the variable to hold the return value of each function.
    int* result3x3 = NULL;
    int* result2x2 = NULL;

    // A different style drive.
    int threeByThreeOrTwoByTwo = 0;
    int threeBy3OpSelection = 0;
    int twoBy2OpSelection = 0;

    bool performMatrixOp = true;
    do
    {   
        Restart:
        printf("\nCalculate operations on:\n\t\t1. [3x3] or 2. [2x2]: ");
        if ((fscanf(stdin, "%i", &threeByThreeOrTwoByTwo)) == 0)
        {   
            fprintf(stderr, "\n\tEither number [1] or [2] please.\n");
            fflush(stdin);
            goto Restart;
        }

        // 1 = 3x3
        // 2 = 2x2
        // Direct the input to either 3x3 functions or 2x2 functions.
        if (threeByThreeOrTwoByTwo == 1)
        {   
            Restart3x3:
            printf("\n -- Matrix [3x3] Operations --");
            printf("\n\t1. Add a 3x3 matrix.");
            printf("\n\t2. Subtract a 3x3 matrix.");
            printf("\n\t3. Multiply a 3x3 matrix.");
            printf("\n\t4. Quit.\n");
            printf("\n\tEnter in a 3x3 operation: ");
            if ((fscanf(stdin, "%i", &threeBy3OpSelection)) == 0)
            {
                fprintf(stderr, "\n\tInvalid selection try again.\n");
                fflush(stdin);
                goto Restart3x3;
            }

            // Is the selection out of range for the particular operations.
            if (!(threeBy3OpSelection >= 1 && threeBy3OpSelection <= 4))
            {
                fprintf(stderr, "\n\tInvalid selection try again.\n");
                fflush(stdin);
                goto Restart3x3;
            }

            // Compare the selection for the proper 3x3 operation.
            switch (threeBy3OpSelection)
            {
                case 1:
                    result3x3 = add3x3Matrix(matrixA_3x3, matrixB_3x3);
                    displayMatrix(result3x3, KROWS3X3, KCOLS3X3);
                    break;
                case 2:
                    result3x3 = subtract3x3Matrix(matrixA_3x3, matrixB_3x3);
                    displayMatrix(result3x3, KROWS3X3, KCOLS3X3);
                    break;
                case 3:
                    result3x3 = multiply3x3Matrix(matrixA_3x3, matrixB_3x3);
                    displayMatrix(result3x3, KROWS3X3, KCOLS3X3);
                    break;
                case 4:
                    free(result3x3);
                    performMatrixOp = false;
                    break;
            }
        }
        else if (threeByThreeOrTwoByTwo == 2)
        {
            Restart2x2:
            printf("\n -- Matrix [2x2] Operations --");
            printf("\n\t1. Add a 2x2 matrix.");
            printf("\n\t2. Subtract a 2x2 matrix.");
            printf("\n\t3. Multiply a 2x2 matrix.");
            printf("\n\t4. Quit.\n");
            printf("\n\tEnter in a 2x2 operation: ");
            if ((fscanf(stdin, "%i", &twoBy2OpSelection)) == 0)
            {
                fprintf(stderr, "\n\tEither number [1] or [2] please.\n");
                fflush(stdin);
                goto Restart2x2;
            }

            // Is the selection out of range for the particular operations.
            if (!(twoBy2OpSelection >= 1 && twoBy2OpSelection <= 4))
            {
                fprintf(stderr, "\n\tInvalid selection try again.\n");
                fflush(stdin);
                goto Restart3x3;
            }

            // Compare the selection for the proper 2x2 operation.
            switch (twoBy2OpSelection)
            {
                case 1:
                    result2x2 = add2x2Matrix(matrixA_2x2, matrixB_2x2);
                    displayMatrix(result2x2, KROWS2X2, KCOLS2X2);
                    break;
                case 2:
                    result2x2 = subtract2x2Matrix(matrixA_2x2, matrixB_2x2);
                    displayMatrix(result2x2, KROWS2X2, KCOLS2X2);
                    break;
                case 3:
                    result2x2 = multiply2x2Matrix(matrixA_2x2, matrixB_2x2);
                    displayMatrix(result2x2, KROWS2X2, KCOLS2X2);
                    break;
                case 4:
                    free(result2x2);
                    performMatrixOp = false;
                    break;
            }
        }
        else
        {
            fprintf(stderr, "\nNot a valid selection try again !\n");
            goto Restart;
        }
    } while (performMatrixOp);
    return 0;
}