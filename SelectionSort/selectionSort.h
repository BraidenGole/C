/**
 * @file selectionSort.h
 * @author Braiden Gole
 * @brief This is a selection sort implementation.
 * @version 0.1
 * @date 2021-01-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KSELECTIONSORT
#define _KSELECTIONSORT "selectionSort.h"

#define __LESSTHAN__ <
#define __LRGRTHAN__ >
#define __PLUS__ +
#define __MINUS__ -
#define __EQ__ ==
#define AMP &

#define SWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define KSIZE 12
#define KZERO 0
#define KONE 1

// Function prototypes.
void sortSelection(int* smallSet, const int size);
void showSelection(int smallSet[], const int size);
#endif