/**
 * @file matrixMethods.c
 * @author Braiden Gole
 * @brief This is a program that deals with matrices.
 * @version 0.1
 * @date 2020-12-27
 * @copyright Copyright (c) 2020
 */
#ifndef _KMATRIXMETHODS
#define _KMATRIXMETHODS "matrixMethods.h"

// Global numeric constants.
#define KROWS3X3 3
#define KCOLS3X3 3
#define KROWS2X2 2
#define KCOLS2X2 2

// Function prototypes.
int* add2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]);
int* subtract2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]);
int* multiply2x2Matrix(int matrixOne[KROWS2X2][KCOLS2X2], int matrixTwo[KROWS2X2][KCOLS2X2]);
int* add3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]);
int* subtract3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]);
int* multiply3x3Matrix(int matrixOne[KROWS3X3][KCOLS3X3], int matrixTwo[KROWS3X3][KCOLS3X3]);
void displayMatrix(int* matrix, const int mRows, const int mCols);
#endif