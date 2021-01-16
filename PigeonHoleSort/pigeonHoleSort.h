/**
 * @file pigeonHoleSort.h
 * @author Braiden Gole
 * @brief This file is used to hold function prototypes and macro constants.
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KPIGEONHOLESORT
#define _KPIGEONHOLESORT "pigeonHoleSort.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define RANGE(assignVar, max, min) { assignVar=max-min + 1; }

#define __LSSTHAN__ <
#define __LRGTHAN__ >
#define __EQ__ ==
#define __NEQ__ !=
#define __PLUS__ +
#define __MINUS__ -

#define KZERO 0
#define KONE 1
#define KMAXSIZE 16

#define KOUTOFMEM "\n\tOut of memory !\n"

// Function prototypes.
const int findMinimum(int* array, const int size);
const int findMaximum(int* array, const int size);
void pigeonHoleSort(int* holes, int* setOfNums, const int size, const int min);
void fillHoles(int* data, int* holeArray, const int size, const int min);
void displaySortedArray(int* array, const int size);
#endif